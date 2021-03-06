#ifndef H_SERVER_H
#define H_SERVER_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include<errno.h>
#include <string.h>
#include <unistd.h>
#include<time.h>
#include<malloc.h>
#include <math.h>
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
#include <sys/types.h>
#include<pthread.h>
#define ADDRESS "192.168.4.45"
#define SHMSZ1 sizeof(cmd)
#define SHMSZ2 sizeof(resp) 
#define SERVER_PORT 5000 // to connect MCM device program 
#define CL_PORT 6000     // to connect to Teleset program 
#define MAX_LOOP 2
#define MAX_ANT 4
#define ABC "C00"
pthread_mutex_t lock;
static unsigned char  *read_ptr ,*write_ptr ;
//static char ABC[10] = "C00";
#define ERROR -1 
extern int sockfd, sfd;
int sockfd, sfd ;
socklen_t clilen;
struct sockaddr_in serv_addr, cli_addr,servaddr;
struct hostent *server;
/*static char at_name[32][8] = {"C00","C01","C02","C03","C04","C05","C06","C08","C10","C11","C12","C13","C00","C14","E02"
           ,"E03","E04","E05","E06","S01","S02","S03","S04","S06","W01","W02","W03","W04","W05","W06"}; */
//enum { MaxProtBuf = 16390 };
enum { MaxProtBuf = 4698 };
enum { MaxProtBuf1 = 1648 };
#pragma pack(push,1)

typedef struct 
{
  int seq;
  char timestamp[64];
  char system_name[16];
  char op_name[16];
  short int number_param;
  char parameter_name[32][16];
  char Argument_Ch1[32][16];
  char Argument_Ch2[32][16];
 } cmd;

typedef struct
{ 
 int response_type;
 int seq;
 char timestamp[64];
 char system_name[16];
 char Mon_raw[64][8];
 char Mon_sum[32][64];   
 short int num_resp_msg;
 char response_message[32][64];  
} resp;



typedef struct
{
  char antenna_name[10];
  cmd  CMD;
} ANT_CMD;

typedef struct
{
  char antenna_name[10];
  resp RESP[10];
}ANT_RESP;

typedef struct
{
  char Ant_name[10];
  char Resp_msg[100];
}ACK;
  
#pragma pack(pop)
extern void write_read(int newsockfd,cmd *c1, resp *r1);
extern void printcmd(cmd *c1);
extern void printresp(resp *r1);
extern int readable_timeo(int fd, int sec);
extern int init_server(void);
extern int connect_to_server();
ssize_t  writen(int fd,  void *vptr, ssize_t n);
ssize_t  readn(int fd, void *vptr, ssize_t maxlen);
ssize_t  read_from_online(int fd, void *vptr, ssize_t maxlen);
#endif //H_SERVER_H
