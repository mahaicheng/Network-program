/*************************************************************************
	> 文件名: 4-23.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月16日 星期一 09时50分53秒
 ************************************************************************/

#include"fifo.h"

void server(int, int);

int main()
{
    int readfifo,writefifo,dumpfd;

    if(mkfifo(SERV_FIFO, FILE_MODE) < 0 && (errno != EEXIST))
        err_sys("can't open %s", SERV_FIFO);

    readfifo = open(SERV_FIFO, O_RDONLY, 0);    //will be block in here
    dumpfd = open(SERV_FIFO, O_WRONLY, 0);      //would not be used

    char buf[MAXLINE];
    int n;
    while((n = readline(readfifo, buf, MAXLINE)) > 0)
    {
        if(buf[n-1] == '\n')
            buf[n-1] = '\0';
    }
}
