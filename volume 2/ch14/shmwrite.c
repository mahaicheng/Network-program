/*************************************************************************
	> 文件名: shmwrite.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 18时39分05秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
        err_quit("Usage: shmwrite <pathname> <base>");

    int base = atoi(argv[2]);

    int shmid = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
    unsigned char *ptr = shmat(shmid, NULL, 0);
    struct shmid_ds buff;
    shmctl(shmid, IPC_STAT, &buff);

    for(int i = 0; i < buff.shm_segsz; i++){
        *ptr++ = i % base;
    }
}
