/*************************************************************************
        > 文件名: client.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月15日 星期五 10时43分31秒
 ************************************************************************/

#include <unpipc.h>
#include "square.h"

int main(int argc, char *argv[]) {
  if (argc != 3) err_quit("Usage: client <hostname> <integer-value>");

  CLIENT *cl = clnt_create(argv[1], SQUARE_PROG, SQUARE_VERS, "tcp");

  square_in in;
  in.arg1 = atol(argv[2]);

  square_out *outp;
  if ((outp = squareproc_1(&in, cl)) == NULL)
    err_quit("%s", clnt_sperror(cl, argv[1]));

  printf("result: %ld\n", outp->res1);
}
