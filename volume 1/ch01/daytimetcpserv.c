/*************************************************************************
	> 文件名: daytimetcpserv.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月21日 星期六 10时20分55秒
 ************************************************************************/

#include<unp.h>

int main()
{
    int listenfd, connfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    time_t tick;
    char buff[MAXLINE];
    while(1)
    {
        connfd = accept(listenfd, (SA*)NULL, NULL);
        tick = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&tick));
        write(connfd, buff, strlen(buff));
        close(connfd);
    }
}
