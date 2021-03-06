#ifndef _SOCKET_H
#define _SOCKET_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include<errno.h>
#include<pthread.h>
#include<time.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <netdb.h>
#include<sys/ioctl.h>

#define PORT 5000

enum { MaxProtBuf = 4698 };
enum { MaxProtBuf1 = 1638 };
//static unsigned char  *read_ptr ,*write_ptr ;
#define ERROR -1 
//extern int sockfd;
//int sockfd;
extern socklen_t clilen;
extern struct sockaddr_in serv_addr, cli_addr;
//static unsigned char  *read_ptr ,*write_ptr ;
socklen_t clilen;
struct sockaddr_in serv_addr, cli_addr;

extern int init_server(int);
ssize_t  writen(int fd,  void *vptr, ssize_t n);
ssize_t  readn(int fd, void *vptr, ssize_t maxlen);
extern int readable_timeo(int fd, int sec);
void terminate_thread(int s);

#endif
