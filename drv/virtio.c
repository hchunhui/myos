#include <os/type.h>
#include <os/arch_config.h>
#include <os/task.h>
#include <lib/klib.h>
#include <os/mm.h>
#include <lib/string.h>
#include <os/io.h>
#include <drv/virtio.h>
#include <os/isr.h>
#include <os/asm.h>
#include <os/sem.h>

// pci
struct pci_dev {
	unsigned int vid;
	unsigned int devid;
	unsigned int busno;
	unsigned int devno;
	unsigned int funcno;
	unsigned int iobase;
	unsigned int irq;
};

static struct pci_dev devs[128];
static int n_devs;

static void pci_scan()
{
	unsigned int bus, device, func, regval, retval;
	unsigned int vid, devid, class3, class2, class1;
	unsigned int iobase, irq;

	n_devs = 0;
	printk("virtio: scan pci...\n");
	printk("\nNo.  Vendor/Device  Bus No.  Dev No.  Func No.  Class");
	for (bus = 0; bus < 5; bus++) {
		for(device = 0; device < 32; device++) {
			for (func = 0; func < 8; func++) {
				regval = 0x80000000
					| (bus << 16)
					| (device << 11)
					| (func << 8);
				outl(regval, 0xCF8);
				retval = inl(0xCFC);
				if (retval != 0xffffffff) {
					vid = retval & 0xffff;
					devid = (retval >> 16) & 0xffff;
					outl(regval + 0x08, 0xCF8);
					retval = inl(0xCFC);
					retval = retval >> 8;
					class3 = retval & 0xff;
					class2 = (retval >> 8) &0xff;
					class1 = (retval >> 16) &0xff;

					outl(regval + 0x10, 0xCF8);
					iobase = inl(0xCFC);
					outl(regval + 0x3C, 0xCF8);
					irq = inl(0xCFC) & 0xff;

					printk("\n%02d   %04x/%04x       %02x       %02x       %02x      %02x-%02x-%02x   %08x  %d",
                                               n_devs, vid, devid, bus, device, func, class1, class2, class3, iobase, irq);
					devs[n_devs].vid = vid;
					devs[n_devs].devid = devid;
					devs[n_devs].busno = bus;
					devs[n_devs].devno = device;
					devs[n_devs].funcno = func;
					devs[n_devs].iobase = iobase&(~1);
					devs[n_devs].irq = irq;
					n_devs++;
					if (func == 0) {
						outl(regval + 0x0C, 0xCF8);
						retval = inl(0xCFC);
						retval = retval >> 16;
						if ((retval & 0x80) == 0) func = 8;
					}
				}
			}
		}
	}
	printk("\nn_devs=%d\n", n_devs);
}

// http://wiki.osdev.org/Virtio
// http://www.dumais.io/index.php?article=aca38a9a2b065b24dfa1dee728062a12
// https://ozlabs.org/~rusty/virtio-spec/virtio-0.9.5.pdf

// vq
#define VIRTIO_PCI_HOST_FEATURES  0
#define VIRTIO_PCI_GUEST_FEATURES 4
#define VIRTIO_PCI_QUEUE_PFN      8
#define VIRTIO_PCI_QUEUE_NUM      12
#define VIRTIO_PCI_QUEUE_SEL      14
#define VIRTIO_PCI_QUEUE_NOTIFY   16
#define VIRTIO_PCI_STATUS         18
#define VIRTIO_PCI_ISR            19

#define VIRTIO_ACKNOWLEDGE 1
#define VIRTIO_DRIVER 2
#define VIRTIO_FAILED 128
#define VIRTIO_FEATURES_OK 8
#define VIRTIO_DRIVER_OK 4
#define VIRTIO_DEVICE_NEEDS_RESET 64

#define VIRTIO_DESC_FLAG_NEXT           1
#define VIRTIO_DESC_FLAG_WRITE_ONLY     2
#define VIRTIO_DESC_FLAG_INDIRECT       4

#define VIRTIO_NET_HDR_F_NEEDS_CSUM    1
#define VIRTIO_NET_HDR_GSO_NONE        0
#define VIRTIO_NET_HDR_GSO_TCPV4       1
#define VIRTIO_NET_HDR_GSO_UDP         3
#define VIRTIO_NET_HDR_GSO_TCPV6       4
#define VIRTIO_NET_HDR_GSO_ECN         0x80

struct vring_desc {
	__u64 addr;
	__u32 len;
	__u16 flags;
	__u16 next;
};

struct vring_avail {
	__u16 flags;
	__u16 idx;
	__u16 ring[];
};

struct vring_used_elem {
	__u32 id;
	__u32 len;
};

struct vring_used {
	__u16 flags;
	__u16 idx;
	struct vring_used_elem ring[];
};

struct virtqueue {
	int queue_size;
	struct vring_desc *desc;
	struct vring_avail *avail;
	struct vring_used *used;
	__u16 last_used_idx;
	void **buffers;
};

struct buffer_info {
	void *buf;
	unsigned int len;
	unsigned int flags;
};

struct virtio_dev;

struct virtio_driver {
	char name[32];
	int devid;
	int nr_vqs;
	void (*set_features)(unsigned char *);
	isr_func int_handler;
	void (*init)(struct virtio_dev *);
	int (*open)(int minor, int mode, void **data);
	int (*close)(int minor, void *data);
	int (*ctl)(int minor, void *data, int cmd, void *arg);
	long (*read)(int minor, void *data, void *buf, long n, long off);
	long (*write)(int minor, void *data, void *buf, long n, long off);
	int (*poll)(int minor, void *data, int func, struct list_head *lsem);
};

struct virtio_dev {
	struct pci_dev *pci;
	struct virtqueue vq[16];
	const struct virtio_driver *driver;
	void *priv;
};

static struct virtio_dev vdevs[128];
static int n_vdevs;

static int page_count(int size)
{
	return (size + PAGE_SIZE - 1) / PAGE_SIZE;
}

void virtqueue_init(struct virtqueue *vq, int queue_size)
{
	if (queue_size == 0) {
		vq->queue_size = 0;
		vq->desc = 0;
		return;
	}

	int size_desc = sizeof(struct vring_desc) * queue_size;
	int size_avail = sizeof(struct vring_avail) + sizeof(__u16) * queue_size;
	int size_used = sizeof(struct vring_used) + sizeof(struct vring_used_elem) * queue_size;
	int pg1 = page_count(size_desc + size_avail);
	int pg2 = page_count(size_used);
	void *buf = kmalloc(PAGE_SIZE * (pg1 + pg2));

	memset(buf, 0, PAGE_SIZE * (pg1 + pg2));

	vq->queue_size = queue_size;
	vq->desc = buf;
	vq->avail = buf + size_desc;
	vq->used = buf + PAGE_SIZE * pg1;
	vq->buffers = kmalloc(sizeof(void *) * queue_size);
}

void virtqueue_deinit(struct virtqueue *vq)
{
	kfree(vq->desc);
	kfree(vq->buffers);
}

static int find_desc_slot(struct vring_desc *desc, int queue_size)
{
	int i;
	for (i = 0; i < queue_size; i++)
		if (desc[i].addr == 0)
			return i;
	panic("find_desc_slot");
}

void virtqueue_add_buf(struct virtqueue *vq, struct buffer_info *data, int count, void *buffer)
{
	int i;
	int did, aid;

	if (count == 0)
		return;

	did = find_desc_slot(vq->desc, vq->queue_size);
	aid = vq->avail->idx & (vq->queue_size - 1);
	vq->avail->ring[aid] = did;
	vq->buffers[did] = buffer;
	for (i = 0; i < count; i++) {
		vq->desc[did].addr = (u64) (unsigned long) data[i].buf;
		vq->desc[did].len = data[i].len;
		vq->desc[did].flags = data[i].flags;
		if (i != count - 1) {
			vq->desc[did].flags |= VIRTIO_DESC_FLAG_NEXT;
			vq->desc[did].next = find_desc_slot(vq->desc, vq->queue_size);
			did = vq->desc[did].next;
		}
	}
	mb();
	vq->avail->idx++;
	mb();
}

int virtqueue_poll(struct virtqueue *vq)
{
	mb();
	return vq->last_used_idx != vq->used->idx;
}

void *virtqueue_get_buf(struct virtqueue *vq, int *plen)
{
	if (!virtqueue_poll(vq)) {
		return NULL;
	} else {
		int uid = vq->last_used_idx & (vq->queue_size - 1);
		int did = vq->used->ring[uid].id;
		int k;

		vq->last_used_idx++;

		for (k = did;
		     vq->desc[k].flags & VIRTIO_DESC_FLAG_NEXT;
		     k = vq->desc[k].next) {
			vq->desc[k].addr = 0;
		}
		vq->desc[k].addr = 0;

		if (plen)
			*plen = vq->used->ring[uid].len;
		return vq->buffers[did];
	}
}

void virtqueue_disable_cb(struct virtqueue *vq)
{
	vq->used->flags = 1;
	mb();
}

/**
 * This re-enables callbacks; it returns "false" if there are pending
 * buffers in the queue, to detect a possible race between the driver
 * checking for more work, and enabling callbacks.
 */
int virtqueue_enable_cb(struct virtqueue *vq)
{
	u16 idx = vq->used->idx;
	mb();
	vq->used->flags = 0;
	mb();
	return idx == vq->used->idx;
}

void virtio_kick(struct virtio_dev *dev, int qid)
{
	outw(qid, dev->pci->iobase + VIRTIO_PCI_QUEUE_NOTIFY);
}

// virtio_blk
#define VIRTIO_BLK_F_SIZE_MAX 1
#define VIRTIO_BLK_F_SEG_MAX 2
#define VIRTIO_BLK_F_GEOMETRY 4
#define VIRTIO_BLK_F_RO 5
#define VIRTIO_BLK_F_BLK_SIZE 6
#define VIRTIO_BLK_F_FLUSH 9
#define VIRTIO_BLK_F_TOPOLOGY 10
#define VIRTIO_BLK_F_CONFIG_WCE 11
#define VIRTIO_BLK_T_IN           0
#define VIRTIO_BLK_T_OUT          1
#define VIRTIO_BLK_T_FLUSH        4
#define VIRTIO_BLK_S_OK        0
#define VIRTIO_BLK_S_IOERR     1
#define VIRTIO_BLK_S_UNSUPP    2

struct block_request_header {
    u32 type;
    u32 reserved;
    u64 sector;
};

static int virtio_blk_int(struct s_regs *pregs, void *data)
{
	struct virtio_dev *vd = data;
	sem_t *psem;

	if ((inb(vd->pci->iobase + VIRTIO_PCI_ISR) & 1) == 0)
		return 1;

	do {
		virtqueue_disable_cb(vd->vq);
		while((psem = virtqueue_get_buf(vd->vq, NULL)))
			sem_up(psem);
	} while (!virtqueue_enable_cb(vd->vq));
	return 0;
}

static void virtio_blk_set_features(unsigned char *f)
{
	*f &= ~VIRTIO_BLK_F_RO;
	*f &= ~VIRTIO_BLK_F_BLK_SIZE;
	*f &= ~VIRTIO_BLK_F_TOPOLOGY;
}

static void virtio_blk_init(struct virtio_dev *vd)
{
	printk("virtio_blk_init: /dev/virtio/%d\n", vd - vdevs);
}

struct virtio_blk_data {
	struct virtio_dev *vd;
	int mode;
	sem_t rsem, wsem;
};

static int virtio_blk_open(int minor, int mode, void **pdata)
{
	struct virtio_blk_data *data = kmalloc(sizeof(struct virtio_blk_data));
	data->vd = vdevs + minor;
	data->mode = mode;
	sem_init(&data->rsem, 0);
	sem_init(&data->wsem, 0);
	*pdata = data;
	return 0;
}

static int virtio_blk_close(int minor, void *data)
{
	kfree(data);
	return 0;
}

static long virtio_blk_read(int minor, void *pdata, void *buf, long n, long off)
{
	struct virtio_blk_data *data = pdata;
	struct virtio_dev *vd = data->vd;

	if (off % 512 || n != 512)
		return -1;

	int sector = off / 512;
	struct buffer_info bi[3];
	char *c = kmalloc(1);
	struct block_request_header *h = kmalloc(sizeof(struct block_request_header));
	char *bufx = kmalloc(512);

	h->type = VIRTIO_BLK_T_IN;
	h->reserved = 0;
	h->sector = sector;
	bi[0].buf = h;
	bi[0].len = sizeof(struct block_request_header);
	bi[0].flags = 0;
	bi[1].buf = bufx;
	bi[1].len = 512;
	bi[1].flags = VIRTIO_DESC_FLAG_WRITE_ONLY;
	bi[2].buf = c;
	bi[2].len = 1;
	bi[2].flags = VIRTIO_DESC_FLAG_WRITE_ONLY;

	virtqueue_add_buf(vd->vq, bi, 3, &data->rsem);
	virtio_kick(vd, 0);

	sem_down(&data->rsem);

	if (*c != 0)
		panic("virtio_blk_read: status: %d\n", *c);
	memcpy(buf, bufx, 512);
	kfree(h);
	kfree(bufx);
	kfree(c);
	return 512;
}

static long virtio_blk_write(int minor, void *pdata, void *buf, long n, long off)
{
	struct virtio_blk_data *data = pdata;
	struct virtio_dev *vd = data->vd;

	if (off % 512 || n != 512)
		return -1;

	int sector = off / 512;
	struct buffer_info bi[3];
	char *c = kmalloc(1);
	struct block_request_header *h = kmalloc(sizeof(struct block_request_header));
	char *bufx = kmalloc(512);

	memcpy(bufx, buf, 512);

	h->type = VIRTIO_BLK_T_OUT;
	h->reserved = 0;
	h->sector = sector;
	bi[0].buf = h;
	bi[0].len = sizeof(struct block_request_header);
	bi[0].flags = 0;
	bi[1].buf = bufx;
	bi[1].len = 512;
	bi[1].flags = 0;
	bi[2].buf = c;
	bi[2].len = 1;
	bi[2].flags = VIRTIO_DESC_FLAG_WRITE_ONLY;

	virtqueue_add_buf(vd->vq, bi, 3, &data->wsem);
	virtio_kick(vd, 0);

	sem_down(&data->wsem);

	if (*c != 0)
		panic("virtio_blk_write: status: %d\n", *c);

	kfree(h);
	kfree(bufx);
	kfree(c);
	return 512;
}

const struct virtio_driver virtio_blk = {
	.name = "virtio_blk",
	.devid = 0x1001,
	.nr_vqs = 1,
	.set_features = virtio_blk_set_features,
	.int_handler = virtio_blk_int,
	.init = virtio_blk_init,
	.open = virtio_blk_open,
	.close = virtio_blk_close,
	.read = virtio_blk_read,
	.write = virtio_blk_write,
};

// virtio_net
#define VIRTIO_CSUM                 0
#define VIRTIO_GUEST_CSUM           1
#define VIRTIO_CTRL_GUEST_OFFLOADS  2
#define VIRTIO_MAC                  5
#define VIRTIO_GUEST_TSO4           7
#define VIRTIO_GUEST_TSO6           8
#define VIRTIO_GUEST_ECN            9
#define VIRTIO_GUEST_UFO            10
#define VIRTIO_HOST_TSO4            11
#define VIRTIO_HOST_TSO6            12
#define VIRTIO_HOST_ECN             13
#define VIRTIO_HOST_UFO             14
#define VIRTIO_MRG_RXBUF            15
#define VIRTIO_STATUS               16
#define VIRTIO_CTRL_VQ              17
#define VIRTIO_CTRL_RX              18
#define VIRTIO_CTRL_VLAN            19
#define VIRTIO_CTRL_RX_EXTRA        20
#define VIRTIO_GUEST_ANNOUNCE       21
#define VIRTIO_MQ                   22
#define VIRTIO_CTRL_MAC_ADDR        23
#define VIRTIO_EVENT_IDX            29

struct net_header
{
    u8 flags;
    u8 gso_type;
    u16 header_length;
    u16 gso_size;
    u16 checksum_start;
    u16 checksum_offset;
};

struct virtio_net_priv {
	unsigned char mac[6];
	sem_t semq;
};

#define FRAME_SIZE 1514

static int virtio_net_int(struct s_regs *pregs, void *data)
{
	struct virtio_dev *vd = data;
	struct virtio_net_priv *priv = vd->priv;

	if ((inb(vd->pci->iobase + VIRTIO_PCI_ISR) & 1) == 0)
		return 1;

	// recv queue
	if (virtqueue_poll(vd->vq) && priv->semq.val < 0) {
		virtqueue_disable_cb(vd->vq);
		sem_up(&priv->semq);
	}

	// send queue
	do {
		sem_t *psem;
		virtqueue_disable_cb(vd->vq + 1);
		while((psem = virtqueue_get_buf(vd->vq + 1, NULL)))
			sem_up(psem);
	} while (!virtqueue_enable_cb(vd->vq + 1));
	return 0;
}

static void virtio_net_set_features(unsigned char *f)
{
    // do not use control queue
    *f &= ~VIRTIO_CTRL_VQ;

    // Disable tcp/udp packet size
    *f &= ~VIRTIO_GUEST_TSO4;
    *f &= ~VIRTIO_GUEST_TSO6;
    *f &= ~VIRTIO_GUEST_UFO;
    *f &= ~VIRTIO_EVENT_IDX;
    *f &= ~VIRTIO_MRG_RXBUF;

    *f |= VIRTIO_CSUM;
}

static void virtio_net_init(struct virtio_dev *vd)
{
	int i;
	unsigned int iobase = vd->pci->iobase;
	struct virtio_net_priv *priv = kmalloc(sizeof(struct virtio_net_priv));

	vd->priv = priv;

	for (i = 0; i < 6; i++)
		priv->mac[i] = inb(iobase + 0x14 + i);

	printk("virtio_net_init: /dev/virtio/%d %02x-%02x-%02x-%02x-%02x-%02x\n",
	       vd - vdevs,
	       priv->mac[0], priv->mac[1], priv->mac[2],
	       priv->mac[3], priv->mac[4], priv->mac[5]);

	// init recv buffers
	sem_init(&priv->semq, 0);
	for (i = 0; i < vd->vq->queue_size; i++) {
		struct buffer_info bi[1];
		struct net_header *h = kmalloc(sizeof(struct net_header) + FRAME_SIZE);

		bi[0].buf = h;
		bi[0].len = sizeof(struct net_header) + FRAME_SIZE;
		bi[0].flags = VIRTIO_DESC_FLAG_WRITE_ONLY;

		virtqueue_add_buf(vd->vq, bi, 1, h);
	}
	virtio_kick(vd, 0);
}

struct virtio_net_data {
	struct virtio_dev *vd;
	int mode;
	sem_t wsem;
	struct list_head poll_read;
};

static int virtio_net_open(int minor, int mode, void **pdata)
{
	struct virtio_net_data *data = kmalloc(sizeof(struct virtio_net_data));
	data->vd = vdevs + minor;
	data->mode = mode;
	sem_init(&data->wsem, 0);
	INIT_LIST_HEAD(&data->poll_read);
	*pdata = data;
	return 0;
}

static int virtio_net_close(int minor, void *data)
{
	kfree(data);
	return 0;
}

static long virtio_net_read(int minor, void *pdata, void *buf, long n, long off)
{
	struct virtio_net_data *data = pdata;
	struct virtio_dev *vd = data->vd;
	struct virtio_net_priv *priv = vd->priv;

	// wait for data
	virtqueue_disable_cb(vd->vq);
	if(!virtqueue_poll(vd->vq)) {
		if(virtqueue_enable_cb(vd->vq))
			sem_down(&priv->semq);
		else
			virtqueue_disable_cb(vd->vq);
	}
	assert(vd->vq->used->flags);

	// dequeue
	int len;
	void *bufx = virtqueue_get_buf(vd->vq, &len);

	assert(bufx);
	len -= sizeof(struct net_header);

	if (len > n)
		len = n;

	// copy data
	memcpy(buf, bufx + sizeof(struct net_header), len);

	// add buf
	struct buffer_info bi[1];
	bi[0].buf = bufx;
	bi[0].len = sizeof(struct net_header) + FRAME_SIZE;
	bi[0].flags = VIRTIO_DESC_FLAG_WRITE_ONLY;
	virtqueue_add_buf(vd->vq, bi, 1, bufx);
	virtio_kick(vd, 0);

	// enable interrupt
	if(!virtqueue_poll(vd->vq))
		virtqueue_enable_cb(vd->vq);

	return len;
}

static long virtio_net_write(int minor, void *pdata, void *buf, long n, long off)
{
	struct virtio_net_data *data = pdata;
	struct virtio_dev *vd = data->vd;
	struct buffer_info bi[2];
	struct net_header *h = kmalloc(sizeof(struct net_header) + n);

	bi[0].buf = h;
	bi[0].len = sizeof(struct net_header) + n;
	bi[0].flags = 0;

	memset(h, 0, sizeof(struct net_header));
	memcpy(h + 1, buf, n);

	virtqueue_add_buf(vd->vq + 1, bi, 1, &data->wsem);
	virtio_kick(vd, 1);

	sem_down(&data->wsem);

	kfree(h);
	return n;
}

static int virtio_net_poll(int minor, void *pdata, int func, struct list_head *lsem)
{
	struct virtio_net_data *data = pdata;
	struct virtio_dev *vd = data->vd;
	switch(func)
	{
	case POLL_FUNC_READABLE:
		return virtqueue_poll(vd->vq);
	case POLL_FUNC_WRITEABLE:
		return 1;
	case POLL_FUNC_REGISTER:
		disable_irq();
		list_add_tail(lsem, &data->poll_read);
		enable_irq();
		return 0;
	case POLL_FUNC_UNREGISTER:
		disable_irq();
		list_del(lsem);
		enable_irq();
		return 0;
	}
	return -1;
}

static int virtio_net_ctl(int minor, void *pdata, int cmd, void *arg)
{
	struct virtio_net_data *data = pdata;
	struct virtio_dev *vd = data->vd;
	struct virtio_net_priv *priv = vd->priv;

	switch(cmd)
	{
	case 0:
		memcpy(arg, priv->mac, 6);
		return 0;
	}
	return -1;
}

const struct virtio_driver virtio_net = {
	.name = "virtio_net",
	.devid = 0x1000,
	.nr_vqs = 2,
	.set_features = virtio_net_set_features,
	.int_handler = virtio_net_int,
	.init = virtio_net_init,
	.open = virtio_net_open,
	.close = virtio_net_close,
	.read = virtio_net_read,
	.write = virtio_net_write,
	.poll = virtio_net_poll,
	.ctl = virtio_net_ctl,
};

// virtio
static void virtio_probe(const struct virtio_driver *driver)
{
	int i, j;
	for (i = 0; i < n_devs; i++) {
		if (devs[i].vid == 0x1AF4 &&
		    devs[i].devid == driver->devid) {
			unsigned int iobase = devs[i].iobase;
			unsigned char feature;

			outb(VIRTIO_ACKNOWLEDGE, iobase + VIRTIO_PCI_STATUS);
			outb(VIRTIO_ACKNOWLEDGE | VIRTIO_DRIVER, iobase + VIRTIO_PCI_STATUS);

			feature = inl(iobase + VIRTIO_PCI_HOST_FEATURES);
			if (driver->set_features)
				driver->set_features(&feature);
			outl(feature, iobase + VIRTIO_PCI_GUEST_FEATURES);

			outb(VIRTIO_ACKNOWLEDGE | VIRTIO_DRIVER | VIRTIO_FEATURES_OK,
			     iobase + VIRTIO_PCI_STATUS);
			if (!(inb(iobase + VIRTIO_PCI_STATUS) & VIRTIO_FEATURES_OK))
				panic("");

			struct virtio_dev *vd = vdevs + n_vdevs;
			n_vdevs++;

			vd->pci = devs + i;
			vd->driver = driver;
			for (j = 0; j < driver->nr_vqs; j++) {
				struct virtqueue *vq = vd->vq + j;
				int queue_size;
				unsigned long pg;
				outw(j, iobase + VIRTIO_PCI_QUEUE_SEL);
				queue_size = inw(iobase + VIRTIO_PCI_QUEUE_NUM);

				virtqueue_init(vq, queue_size);
				pg = ((unsigned long) vq->desc) / PAGE_SIZE;
				outl(pg, iobase + VIRTIO_PCI_QUEUE_PFN);
			}

			outb(VIRTIO_ACKNOWLEDGE | VIRTIO_DRIVER |
			     VIRTIO_FEATURES_OK | VIRTIO_DRIVER_OK,
			     iobase + VIRTIO_PCI_STATUS);

			if (driver->int_handler) {
				irq_register(devs[i].irq, driver->int_handler, vd);
				pic_enable_irq(devs[i].irq);
			}

			if (driver->init)
				driver->init(vd);
		}
	}
}

static int virtio_init()
{
	pci_scan();
	virtio_probe(&virtio_blk);
	virtio_probe(&virtio_net);
	return 0;
}

static int virtio_open(int minor, int mode, void **data)
{
	if (minor < 0 || minor >= n_vdevs)
		return -1;
	if (vdevs[minor].driver->open)
		return vdevs[minor].driver->open(minor, mode, data);
	return -1;
}

static int virtio_close(int minor, void *data)
{
	if (minor < 0 || minor >= n_vdevs)
		return -1;
	if (vdevs[minor].driver->close)
		return vdevs[minor].driver->close(minor, data);
	return -1;
}

static int virtio_ctl(int minor, void *data, int cmd, void *arg)
{
	if (minor < 0 || minor >= n_vdevs)
		return -1;
	if (vdevs[minor].driver->ctl)
		return vdevs[minor].driver->ctl(minor, data, cmd, arg);
	return -1;
}

static long virtio_read(int minor, void *data, void *buf, long n, long off)
{
	if (minor < 0 || minor >= n_vdevs)
		return -1;
	if (vdevs[minor].driver->read)
		return vdevs[minor].driver->read(minor, data, buf, n, off);
	return -1;
}

static long virtio_write(int minor, void *data, void *buf, long n, long off)
{
	if (minor < 0 || minor >= n_vdevs)
		return -1;
	if (vdevs[minor].driver->write)
		return vdevs[minor].driver->write(minor, data, buf, n, off);
	return -1;
}

static int virtio_poll(int minor, void *data, int func, struct list_head *lsem)
{
	if (minor < 0 || minor >= n_vdevs)
		return -1;
	if (vdevs[minor].driver->poll)
		return vdevs[minor].driver->poll(minor, data, func, lsem);
	return -1;
}

struct dev_desc virtio_dev_desc = {
	.name = "virtio",
	.init = virtio_init,
	.open = virtio_open,
	.close = virtio_close,
	.ctl = virtio_ctl,
	.read = virtio_read,
	.write = virtio_write,
	.poll = virtio_poll,
};
