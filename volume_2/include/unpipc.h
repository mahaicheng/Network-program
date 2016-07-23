/*************************************************************************
	> 文件名: unpipc.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2015年11月13日 星期五 18时13分17秒
 ************************************************************************/

#ifndef _UNPIPC_H_
#define _UNPIPC_H_

#define _GNU_SOURCE
//#define _XOPEN_SOURCE

#include<sys/types.h>
#include<sys/time.h>
#include<time.h>
#include<errno.h>
#include<fcntl.h>
#include<limits.h>
#include<stdarg.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>

//posix IPC
    #include<mqueue.h>
    #include<semaphore.h>
    #include<sys/mman.h>

//system V IPC 
    #include<sys/ipc.h>
    #include<sys/msg.h>
    #include<sys/sem.h>
    #include<sys/shm.h>

    #include<sys/select.h>
    #include<poll.h>
    #include<stropts.h>
    #include<strings.h>

    #include<sys/ioctl.h>
    #include<pthread.h>
    #include<rpc/rpc.h>

#ifndef PATH_MAX
    #define PATH_MAX 1024
#endif

#define MAX_PATH 1024
#define MAXLINE  4096
#define BUFFSIZE 8192

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define DIR_MODE  (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

//for message queues
#define MSG_R 0400
#define MSG_W 0200

//for semaphore
#define SEM_R 0400
#define SEM_A 0200

//for shared memory
#define SHM_R 0400
#define SHM_W 0200

#define SVMSG_MODE (MSG_R | MSG_W | MSG_R >> 3 | MSG_R >> 6)
#define SVSEM_MODE (SEM_R | SEM_A | SEM_R >> 3 | SEM_R >> 6)
#define SVSHM_MODE (SHM_R | SHM_W | SHM_R >> 3 | SHM_R >> 6)

typedef void Sigfunc(int);

typedef void Sigfunc_rt(int, siginfo_t*, void*);

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#ifdef __bsdi__
    #define va_mode_t int
#else
    #define va_mode_t mode_t
#endif

#define read_lock(fd, offset, whence, len) \
        lock_reg(fd, F_SETLK, F_RDLCK, offset, whence, len)
#define readw_lock(fd, offset, whence, len) \
        lock_reg(fd, F_SETLKW, F_RDLCK, offset, whence, len)
#define write_lock(fd, offset, whence, len) \
        lock_reg(fd, F_SETLK, F_WRLCK, offset, whence, len)
#define writew_lock(fd, offset, whence, len) \
        lock_reg(fd, F_SETLKW, F_WRLCK, offset, whence, len)
#define un_lock(fd, offset, whence, len) \
        lock_reg(fd, F_SETLK, F_UNLCK, offset, whence, len)
#define is_read_lockable(fd, offset, whence, len) \
        lock_test(fd, F_RDLCK, offset, whence, len)
#define is_write_lockable(fd, offset, whence, len) \
        lock_test(fd, F_WRLCK, offset, whence, len)

//self-defined function declarations

void err_ret(const char*, ...);
void err_sys(const char*, ...);
void err_dump(const char*, ...);
void err_msg(const char*, ...);
void err_quit(const char*, ...);
void err_doit(int, int, const char*, va_list);

#endif
