#ifndef _SPEAKER_H_
#define _SPEAKER_H_
int drv_speaker_open(int pid);
int drv_speaker_read(int pid, int fd, void *buf, int count);
int drv_speaker_write(int pid, int fd, void *buf, int count);
int drv_speaker_close(int pid);

#endif
