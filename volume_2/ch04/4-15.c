/*************************************************************************
	> 文件名: 4-15.c
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月15日 星期日 15时23分29秒
 ************************************************************************/

#include<unpipc.h>
#include<stdio.h>

int main()
{
    char buf[MAXLINE], commond[MAXLINE];

    fgets(buf, MAXLINE, stdin);
    int n = strlen(buf);
    if(buf[n-1] == '\n')
        n--;
    snprintf(commond, sizeof(commond), "cat %s", buf);
    FILE* fp = popen(commond, "r");

    while(fgets(buf, MAXLINE, fp) != NULL)
        fputs(buf, stdout);

    pclose(fp);
}
