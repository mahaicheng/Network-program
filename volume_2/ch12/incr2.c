/*************************************************************************
        > 文件名: incr2.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 16时05分28秒
 ************************************************************************/

#include <unpipc.h>

#define SEM_NAME "mysem"

int main(int argc, char *argv[]) {
  if (argc != 3) err_quit("Usage: incr2 <pathname> <#loops>");

  int nloops = atoi(argv[2]);

  int zero = 0;
  int fd = open(argv[1], O_RDWR | O_CREAT, FILE_MODE);
  write(fd, &zero, sizeof(int));
  int *ptr = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  close(fd);

  sem_t *mutex = sem_open(SEM_NAME, O_CREAT | O_EXCL, FILE_MODE, 1);
  sem_unlink(SEM_NAME);

  setbuf(stdout, NULL);

  if (fork() == 0) {  // child
    int i = 0;
    while (i < nloops) {
      sem_wait(mutex);
      printf("child: %d\n", (*ptr)++);
      i++;
      sem_post(mutex);
    }
    exit(0);
  }

  // parent
  int i = 0;
  while (i < nloops) {
    sem_wait(mutex);
    printf("parent: %d\n", (*ptr)++);
    i++;
    sem_post(mutex);
  }
}
