/*************************************************************************
	> 文件名: msgsnd.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月19日 星期四 09时13分40秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char* argv[])
{
    if(argc != 4)
        err_quit("usage: msgsnd <pathname> <#byte> <type>");

    int len = atoi(argv[2]);
    long type = atoi(argv[3]);

    int mqid = msgget(ftok(argv[1], 0), MSG_W);

    struct msgbuf *ptr;
    ptr = calloc(sizeof(long) + len, sizeof(char));
    ptr->mtype = type;

    msgsnd(mqid, ptr, len, 0);
}
