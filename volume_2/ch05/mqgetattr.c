/*************************************************************************
	> 文件名: mqgetattr.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月19日 星期四 08时09分39秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
        err_quit("usage: mqgetattr <name>");

    mqd_t mqd;
    struct mq_attr attr;

    mqd = mq_open(argv[1], O_RDONLY);
    mq_getattr(mqd, &attr);

    printf("max #msgs = %ld, max #bytes/msg = %ld, #currently on queue = %ld\n", attr.mq_maxmsg, attr.mq_msgsize, attr.mq_curmsgs);

    mq_close(mqd);
}
