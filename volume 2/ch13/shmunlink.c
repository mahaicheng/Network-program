/*************************************************************************
	> 文件名: shmunlink.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 17时01分56秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
        err_quit("Usage: shmunlink <name>");

    shm_unlink(argv[1]);
}
