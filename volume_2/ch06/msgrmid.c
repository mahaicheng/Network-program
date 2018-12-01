/*************************************************************************
        > 文件名: msgrmid.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 13时43分43秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usgae: msgrmid <pathname>");

  int mqid = msgget(ftok(argv[1], 0), 0);
  msgctl(mqid, IPC_RMID, NULL);
}
