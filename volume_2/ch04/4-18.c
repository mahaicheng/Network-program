/*************************************************************************
        > 文件名: 4-18.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月15日 星期日 16时27分32秒
 ************************************************************************/

#include "fifo.h"

void server(int, int);

int main() {
  int readfd, writefd;

  if (mkfifo(FIFO1, FILE_MODE) < 0 && (errno != EEXIST))
    err_sys("can't create %s", FIFO1);
  if (mkfifo(FIFO2, FILE_MODE) < 0 && (errno != EEXIST)) {
    unlink(FIFO1);
    err_sys("can't create %s", FIFO2);
  }

  readfd = open(FIFO1, O_RDONLY, 0);
  writefd = open(FIFO2, O_WRONLY, 0);

  server(readfd, writefd);
}

void server(int readfd, int writefd) {
  char buf[MAXLINE];

  int n;
  if ((n = read(readfd, buf, MAXLINE)) == 0)
    err_quit("end-of-file while reading pathname");

  buf[n] = '\0';  // end of a char-type string

  int fd;
  if ((fd = open(buf, O_RDONLY)) < 0) {
    snprintf(buf + n, sizeof(buf) - n, ": can't open, %s\n", strerror(errno));
    n = strlen(buf);
    write(writefd, buf, n);
  } else {
    while ((n = read(fd, buf, MAXLINE)) > 0) write(writefd, buf, n);

    close(fd);
  }
}
