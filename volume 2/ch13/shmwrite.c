/*************************************************************************
	> 文件名: shmwrite.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 17时18分26秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    if(argc != 2) 
        err_quit("Usage: shmwrite <name>");

    int fd = shm_open(argv[1], O_RDWR, FILE_MODE);
    struct stat stat;
    fstat(fd, &stat);
    int *ptr = mmap(NULL, stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);

    for(int i = 0; i < stat.st_size; i++)
        *ptr++ = i % 17;
}
