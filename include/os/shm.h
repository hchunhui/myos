#ifndef _SHM_H_
#define _SHM_H_

#define SHM_R  1
#define SHM_W  2
#define SHM_RW (SHM_R | SHM_W)

void shm_init();

int shm_at(int key, unsigned long base_addr, unsigned int flag);

int shm_dt(int key, unsigned long base_addr);

int shm_get(int key, unsigned long size);

int shm_free(int key);
#endif
