/*************************************************************************
        > 文件名: semcreate.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 15时14分23秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  int oflag = SVSEM_MODE | IPC_CREAT;

  int c;
  while ((c = getopt(argc, argv, "e")) != -1) {
    switch (c) {
      case 'e':
        oflag |= IPC_EXCL;
        break;
    }
  }

  if (optind != argc - 2) err_quit("Usage: semcreate [-e] <pathname> <nsems>");

  int nsems = atoi(argv[optind + 1]);
  semget(ftok(argv[optind], 0), nsems, oflag);
}
