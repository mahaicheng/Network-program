/*************************************************************************
	> 文件名: semcreate.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月11日 星期一 20时27分14秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    unsigned int value = 1;
    int flags = O_RDWR | O_CREAT;

    int c;
    while((c = getopt(argc, argv, "ei:")) != -1){
        switch(c){
            case 'e':
                flags |= O_EXCL;
                break;
            case 'i':
                value = atoi(optarg);
                break;
        }
    }

    if(optind != argc - 1)
        err_quit("Usage: semcreate [-e] [-i initvalue] <name>");

    sem_t *sem = sem_open(argv[optind], flags, FILE_MODE, value);
    //sem_close(sem);
}

