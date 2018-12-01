/*************************************************************************
        > 文件名: mqcreate.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月19日 星期四 08时28分45秒
 ************************************************************************/

#include <unpipc.h>

struct mq_attr attr;

int main(int argc, char* argv[]) {
  int flags = O_RDWR | O_CREAT;

  int c;
  while ((c = getopt(argc, argv, "em:z:h")) != -1) {
    switch (c) {
      case 'e':
        flags |= O_EXCL;
        break;

      case 'm':
        attr.mq_maxmsg = atol(optarg);
        break;

      case 'z':
        attr.mq_msgsize = atol(optarg);
        break;

      case 'h':
        printf("\nusage: mqcreate [-e] [-m maxmsg] [-z msgsize] <name>\n\n");
        printf("DETAILS:\n");
        printf("\t-e\t\tset EXCL option\n");
        printf("\t-m maxmsg\tset the max number messages on system\n");
        printf("\t-z msgsize\tset the max size of a message\n\n");
        exit(EXIT_SUCCESS);
    }
  }

  if (optind != argc - 1)
    err_quit("usage: mqcreate [-e] [-m maxmsg] [-z msgsize] <name>");

  if ((attr.mq_maxmsg != 0 && attr.mq_msgsize == 0) ||
      (attr.mq_maxmsg == 0 && attr.mq_msgsize != 0))
    err_quit("must specify both -m maxmsg and -z msgsize");

  mqd_t mqd = mq_open(argv[optind], flags, FILE_MODE,
                      (attr.mq_maxmsg != 0) ? &attr : NULL);

  mq_close(mqd);
}
