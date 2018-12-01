/*************************************************************************
        > 文件名: daytimetcpcli.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2015年11月21日 星期六 10时03分37秒
 ************************************************************************/

#include <unp.h>

int main(int argc, char* argv[]) {
  if (argc != 2) err_quit("usage: %s <IP address>", argv[0]);

  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) err_sys("socket error");

  struct sockaddr_in servaddr;
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8888);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    err_quit("inet_pton, error for %s", argv[1]);

  if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) < 0)
    err_sys("connect error");

  int n;
  char recvline[MAXLINE + 1];
  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = '\0';
    if (fputs(recvline, stdout) == EOF) err_sys("fputs error");
  }

  if (n < 0) err_sys("read error");
}
