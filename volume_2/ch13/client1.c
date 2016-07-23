/*************************************************************************
	> 文件名: client1.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 17时50分16秒
 ************************************************************************/

#include<unpipc.h>

struct shmstruct
{
    int count;
};

int main(int argc, char *argv[])
{
    if(argc != 4)
        err_quit("Usage: client1 <shmname> <semname> <#loops>");

    int nloops = atoi(argv[3]);

    int fd = shm_open(argv[1], O_RDWR, FILE_MODE);
    struct shmstruct *ptr = mmap(NULL, sizeof(struct shmstruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    sem_t *mutex = sem_open(argv[2], 0);

    int pid = getpid();

    for(int i = 0; i < nloops; i++){
        sem_wait(mutex);
        printf("pid = %d: %d\n", pid, ptr->count++);
        sem_post(mutex);
    }
}
