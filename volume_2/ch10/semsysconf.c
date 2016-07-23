/*************************************************************************
	> 文件名: semsysconf.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年01月14日 星期四 15时07分58秒
 ************************************************************************/

#include<unpipc.h>

int main(int argc, char *argv[])
{
    printf("SEM_NSEMS_MAX = %ld, SEM_VALUE_MAX = %ld\n", \
          sysconf(_SC_SEM_NSEMS_MAX), sysconf(_SC_SEM_VALUE_MAX));
}
