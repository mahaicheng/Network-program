/*************************************************************************
        > 文件名: 4-8.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月15日 星期日 14时54分01秒
 ************************************************************************/

#include <unpipc.h>

void client(int, int);
void server(int, int);

#define FIFO1 "/tmp/ma_fifo_1"

#define FIFO2 "/tmp/ma_fifo_2"

int main() {
  if (mkfifo(FIFO1, FILE_MODE) < 0 && (errno != EEXIST))
    err_sys("can't create %s", FIFO1);
  if (mkfifo(FIFO2, FILE_MODE) < 0 && (errno != EEXIST)) {
    unlink(FIFO1);  // FIFO1 has been create successfully
    err_sys("can't create %s", FIFO2);
  }
  int readfd, writefd;
  pid_t childpid;
  if ((childpid = fork()) == 0) {  // child
    readfd = open(FIFO1, O_RDONLY, 0);
    writefd = open(FIFO2, O_WRONLY, 0);
    server(readfd, writefd);
    exit(0);
  }

  // parent
  writefd =
      open(FIFO1, O_WRONLY,
           0);  // Must to open FIFO1 first. Otherwise, a deadlock may occurs.
  readfd = open(FIFO2, O_RDONLY, 0);
  // writefd = open(FIFO1, O_WRONLY, 0);
  client(readfd, writefd);

  waitpid(childpid, NULL, 0);

  close(readfd);
  close(writefd);

  unlink(FIFO1);
  unlink(FIFO2);
}

void client(int readfd, int writefd) {
  char buf[MAXLINE];

  fgets(buf, MAXLINE, stdin);

  int len = strlen(buf);
  if (buf[len - 1] == '\n') len--;

  write(writefd, buf, len);

  int n;
  while ((n = read(readfd, buf, MAXLINE)) > 0) write(STDOUT_FILENO, buf, n);
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
