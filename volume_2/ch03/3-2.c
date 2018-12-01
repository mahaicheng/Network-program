/*************************************************************************
        > 文件名: 3-2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月14日 星期六 14时55分27秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char* argv[]) {
  if (argc != 2) err_quit("usage: %s <pathname>", argv[0]);

  struct stat statbuf;

  stat(argv[1], &statbuf);

  printf("st_dev: %lx, st_ino: %lx, key: %x\n", (u_long)statbuf.st_dev,
         (u_long)statbuf.st_ino, ftok(argv[1], 0x57));
}
