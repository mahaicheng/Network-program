/*************************************************************************
        > 文件名: sempost.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月11日 星期一 21时10分15秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: sempost <name>");

  sem_t *sem = sem_open(argv[1], 0);
  sem_post(sem);
  printf("post a semaphore\n");
}
