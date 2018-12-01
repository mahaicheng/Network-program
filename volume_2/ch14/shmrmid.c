/*************************************************************************
        > 文件名: shmrmid.c
        > 作者: 马海城
        > 邮箱: hchma@outlook.com
        > 创建日期: 2016年01月14日 星期四 18时33分17秒
 ************************************************************************/

#include <unpipc.h>

int main(int argc, char *argv[]) {
  if (argc != 2) err_quit("Usage: shmrmid <pathname>");

  int shmid = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
  shmctl(shmid, IPC_RMID, NULL);
}
