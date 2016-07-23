/*************************************************************************
	> 文件名: unpipc.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月13日 星期五 18时13分17秒
 ************************************************************************/

#ifndef _UNPIPC_H_
#define _UNPIPC_H_

#include<sys/types.h>
#include<sys/socket.h>
#include<sys/time.h>
#include<time.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<fcntl.h>
#include<netdb.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/uio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/un.h>

#include<sys/select.h>
#include<poll.h>

#include<sys/sysctl.h>

#include<strings.h>

#include<sys/ioctl.h>

#include<pthread.h>

#define INADDR_NONE 0xffffffff

#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2

#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46

//#define bzero(ptr,n) memset(ptr,0,n)

#define gethostbyname2(host,family) gethostbyname((host))

struct unp_in_pktinfo
{
    struct in_addr  ipi_addr;
    int             ipi_ifindex;
};

#define CMSG_LEN(size) (sizeof(struct cmsghdr) + size)
#define CMSG_SPACE(size) (sizeof(struct cmsghdr)+size)

#define SUN_LEN(su) \
        (sizeof((su))-sizeof(su.sun_path)+strlen(su.sun_path))

//#define AF_LOCAL AF_UNIX
//#define PF_LOCAL PF_UNIX

#define INFTIM (-1)
#define INFTIM_UNPH

#define LISTENQ 1024

#define MAXLINE 4096
#define BUFFSIZE 8192

#define SERV_PORT 9877
#define SERV_PORT_STR "9877"
#define UNIXSTR_PATH "/tmp/unix.str"
#define UNIXDG_PATH  "/tmp/unix.dg"

#define SA struct sockaddr

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE  (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) < (b) ? (a) : (b))

void err_ret(const char *, ...);
void err_sys(const char *, ...);
void err_dump(const char *, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);

#endif
