/*************************************************************************
        > 文件名: mqsend.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 13时22分14秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 4) err_quit("Usage: mqsend <name> <#bytes> <priority>");

  size_t len = atoi(argv[2]);
  unsigned int prio = atoi(argv[3]);

  mqd_t mqd = mq_open(argv[1], O_WRONLY);

  void *ptr = calloc(len, sizeof(char));
  mq_send(mqd, ptr, len, prio);
}
