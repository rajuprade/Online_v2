#include"server.h"
extern socklen_t clilen;
extern struct sockaddr_in serv_addr, cli_addr;
int init_server(void)
{
      int reuse =1;
      struct linger wrplinger = { 0 , 0 };
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0) 
      fprintf(stderr,"ERROR opening socket\n");

      if( setsockopt(sockfd, SOL_SOCKET, SO_LINGER, &wrplinger, sizeof(wrplinger)) == ERROR)
           {
              fprintf(stderr,"setsockopt-SO_LINGER"); 
              return ERROR; 
           } 

      if( setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == ERROR)
           { 
               fprintf(stderr,"setsockopt-SO_REUSEADDR");
               return ERROR; 
           }
     if( setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &reuse, sizeof(reuse)) == ERROR)
             { 
               fprintf(stderr,"setsockopt-SO_KEEPALIVE");
               return ERROR; 
            }
  
     if(setsockopt(sockfd, IPPROTO_TCP,TCP_NODELAY, (char *)&reuse,sizeof(reuse)) == ERROR)
       { 
          fprintf(stderr,"setsockopt_TCP_NODELAY");
          return ERROR;
       }   

       bzero((char *) &serv_addr, sizeof(serv_addr));
  
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(PORT);

     if (bind(sockfd, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
              { 
               fprintf(stderr,"ERROR binding socket\n");
              }

     listen(sockfd,5);
     return 0;
}
