/*************************************************************************
	> 文件名: 4-8.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月15日 星期日 14时54分01秒
 ************************************************************************/

#include<unpipc.h>

void client(int, int);
void server(int, int);

int main()
{
    int pipe1[2], pipe2[2];
    pid_t childpid;

    pipe(pipe1);
    pipe(pipe2);

    if((childpid = fork()) == 0) //child
    {
        close(pipe1[1]);
        close(pipe2[0]);

        server(pipe1[0], pipe2[1]);
        exit(0);
    }
    
    //parent
    
    close(pipe1[0]);
    close(pipe2[1]);

    client(pipe2[0], pipe1[1]);

    waitpid(childpid, NULL, 0);
}

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

void server(int readfd, int writefd)
{
    char buf[MAXLINE];

    int n;
    if((n = read(readfd, buf, MAXLINE)) == 0)
        err_quit("end-of-file while reading pathname");

    buf[n] = '\0'; //end of a char-type string

    int fd;
    if((fd = open(buf, O_RDONLY)) < 0)
    {
        snprintf(buf+n, sizeof(buf)-n, ": can't open, %s\n", strerror(errno));
        n = strlen(buf);
        write(writefd, buf, n);
    }
    else
    {
        while((n = read(fd, buf, MAXLINE)) > 0)
        write(writefd, buf, n);

        close(fd);
    }
}
