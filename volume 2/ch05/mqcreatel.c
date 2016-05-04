/*************************************************************************
	> 文件名: 5-2.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月18日 星期三 20时31分45秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char* argv[])
{
    int flags = O_RDWR | O_CREAT;
    
    int c;
    while((c = getopt(argc, argv, "e")) != -1)
    {
        switch(c)
        {
            case 'e' :
                flags |= O_EXCL;
                break;
        }
    }

    if(optind != argc - 1)
        err_quit("Usage: %s [-e] <name>", argv[0]);

    mqd_t mqd = mq_open(argv[optind], flags, FILE_MODE, NULL);
    mq_close(mqd);
}
