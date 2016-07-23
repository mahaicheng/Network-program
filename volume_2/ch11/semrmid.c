/*************************************************************************
	> 文件名: semrmid.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 15时21分33秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
        err_quit("Usage: semrmid <pathname>");

    semctl(semget(ftok(argv[1], 0), 0, 0), 0, IPC_RMID);
}
