/*************************************************************************
        > 文件名: unixbind.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月20日 星期三 10时30分33秒
 ************************************************************************/

#include <unp.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: unixbind <pathname>");

  int sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);

  unlink(argv[1]);

  struct sockaddr_un addr1, addr2;
  bzero(&addr1, sizeof(addr1));
  addr1.sun_family = AF_LOCAL;
  strncpy(addr1.sun_path, argv[1], sizeof(addr1.sun_path) - 1);
  bind(sockfd, (struct sockaddr *)&addr1, SUN_LEN(addr1));

  socklen_t len = sizeof(addr2);
  getsockname(sockfd, (SA *)&addr2, &len);

  printf("bound name = %s, returned len = %d\n", addr2.sun_path, len);
}
