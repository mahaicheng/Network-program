/*************************************************************************
	> 文件名: 3-7.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月14日 星期六 15时30分01秒
 ************************************************************************/

#include<unpipc.h>

int main()
{
    int i, msqid;

    for(i = 0; i < 10; ++i)
    {
        msqid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);
        printf("msqid = %d\n", msqid);

        //msgctl(msqid, IPC_RMID, NULL);
    }
}
