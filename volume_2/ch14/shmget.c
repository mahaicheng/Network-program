/*************************************************************************
        > 文件名: shmget.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 18时20分55秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  int oflag = SVSHM_MODE | IPC_CREAT;

  int c;
  while ((c = getopt(argc, argv, "e")) != -1) {
    switch (c) {
      case 'e':
        oflag |= O_EXCL;
        break;
    }
  }

  if (optind != argc - 2) err_quit("Usage: shmget [-e] <pathname> <length>");

  int length = atoi(argv[optind + 1]);
  int shmid = shmget(ftok(argv[optind], 0), length, oflag);
  shmat(shmid, NULL, 0);
}
