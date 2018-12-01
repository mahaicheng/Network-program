/*************************************************************************
        > 文件名: semunlink.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月11日 星期一 20时49分37秒
 ************************************************************************/
#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: semunlink <name>");

  sem_unlink(argv[1]);
}
