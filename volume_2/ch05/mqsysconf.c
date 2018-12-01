/*************************************************************************
        > 文件名: 5-8.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月18日 星期三 21时18分15秒
 ************************************************************************/

#include <unpipc.h>

int main() {
  printf("MQ_OPEN_MAX = %ld, MQ_PRIO_MAX = %ld\n", sysconf(_SC_MQ_OPEN_MAX),
         sysconf(_SC_MQ_PRIO_MAX));
}
