/*************************************************************************
	> 文件名: msgcreate.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月18日 星期三 22时19分57秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char* argv[])
{
    int oflag = SVMSG_MODE | IPC_CREAT;

    int c;
    while((c = getopt(argc, argv, "e")) != -1)
    {
        switch(c)
        {
            case 'e' :
                oflag |= IPC_EXCL;
                break;
        }
    }

    if(optind != argc - 1)
        err_quit("usage: msgcreate [-e] <pathname>");

    int msqid = msgget(ftok(argv[optind], 0), oflag);
}
