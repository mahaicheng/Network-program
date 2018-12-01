/*************************************************************************
        > 文件名: semgetvalue.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月11日 星期一 20时51分20秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: semgetvalue <name>");

  sem_t *sem = sem_open(argv[1], 0);
  int val;
  sem_getvalue(sem, &val);
  printf("value = %d\n", val);
}
