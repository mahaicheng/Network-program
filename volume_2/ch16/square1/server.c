/*************************************************************************
        > 文件名: server.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月15日 星期五 10时52分00秒
 ************************************************************************/

#include <unpipc.h>
#include "square.h"

square_out *squareproc_1_svc(square_in *inp, struct svc_req *rqstp) {
  static square_out out;
  out.res1 = inp->arg1 * inp->arg1;
  return &out;
}
