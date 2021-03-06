/*************************************************************************
        > 文件名: shmread.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 18时46分41秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: shmread <pathname>");

  int shmid = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
  unsigned char *ptr = shmat(shmid, NULL, 0);
  struct shmid_ds buff;
  shmctl(shmid, IPC_STAT, &buff);

  for (int i = 0; i < buff.shm_segsz; i++, ptr++) {
    printf("ptr[%d] = %d\n", i, *ptr);
  }
}
