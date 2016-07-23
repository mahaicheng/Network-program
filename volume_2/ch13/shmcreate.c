/*************************************************************************
	> 文件名: shmcreate.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 17时09分09秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    int flags = O_RDWR | O_CREAT;

    int c;
    while((c = getopt(argc, argv, "e")) != -1){
        switch(c){
            case 'e':
                flags |= O_EXCL;
                break;
        }
    }

    if(optind != argc - 2)
        err_quit("Usage: shmcreate [-e] <name> <length>");

    int length = atoi(argv[optind+1]);
    int fd = shm_open(argv[optind], flags, FILE_MODE);
    ftruncate(fd, length);
    mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
}
