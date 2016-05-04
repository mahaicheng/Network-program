/*************************************************************************
	> 文件名: 4-20.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月15日 星期日 16时42分03秒
 ************************************************************************/

#include"fifo.h"

void client(int readfd, int writefd)
{
    char buf[MAXLINE];

    fgets(buf, MAXLINE, stdin);

    int len = strlen(buf);
    if(buf[len-1] == '\n')
        len--;

    write(writefd, buf, len);

    int n;
    while((n = read(readfd, buf, MAXLINE)) > 0)
        write(STDOUT_FILENO, buf, n);
}

int main()
{
    int readfd, writefd;
    writefd = open(FIFO1, O_WRONLY, 0);
    readfd = open(FIFO2, O_RDONLY, 0);

    client(readfd, writefd);

    close(readfd);
    close(writefd);

    unlink(FIFO1);
    unlink(FIFO2);
}
