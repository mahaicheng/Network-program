/*************************************************************************
        > 文件名: incr1.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 15时33分32秒
 ************************************************************************/

#include <unpipc.h>

#define SEM_NAME "mysem"

int count = 0;

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: incr1 <#loops>");

  int nloops = atoi(argv[1]);
  sem_t *mutex = sem_open(SEM_NAME, O_CREAT | O_EXCL, FILE_MODE, 1);
  sem_unlink(SEM_NAME);

  setbuf(stdout, NULL);

  if (fork() == 0) {  // child
    int i;
    for (i = 0; i < nloops; i++) {
      sem_wait(mutex);
      printf("child: %d\n", count++);
      sem_post(mutex);
    }
    exit(0);
  }

  // parent
  int i;
  for (i = 0; i < nloops; i++) {
    sem_wait(mutex);
    printf("parent: %d\n", count++);
    sem_post(mutex);
  }
}
