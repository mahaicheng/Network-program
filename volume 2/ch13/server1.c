/*************************************************************************
	> 文件名: server1.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 17时43分20秒
 ************************************************************************/

#include<unpipc.h>

struct shmstruct
{
    int count;
};

int main(int argc, char *argv[])
{
    if(argc != 3)
        err_quit("Usage: server1 <shmname> <semname>");

    shm_unlink(argv[1]);

    int fd = shm_open(argv[1], O_RDWR | O_CREAT | O_EXCL, FILE_MODE);
    ftruncate(fd, sizeof(struct shmstruct));
    int *ptr = mmap(NULL, sizeof(struct shmstruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    sem_unlink(argv[2]);
    sem_t *mutex = sem_open(argv[2], O_CREAT | O_EXCL, FILE_MODE, 1);
    sem_close(mutex);
}
