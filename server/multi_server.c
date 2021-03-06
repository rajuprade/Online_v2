#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 6782

int main(int argc, char **argv) {

  fd_set fds, readfds;
  int i, clientaddrlen,rval,yes;
  char buf[1024];
  int clientsock[2], rc, numsocks = 0, maxsocks = 2;

  int serversock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (serversock == -1) perror("Socket");
  
     if(setsockopt(serversock, SOL_SOCKET , SO_REUSEADDR, &yes, sizeof(int)) == -1)
    {
          fprintf(stderr," ADDRESS RU Error\n");
    } 

  struct sockaddr_in serveraddr, clientaddr;  
  bzero(&serveraddr, sizeof(struct sockaddr_in));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serveraddr.sin_port = htons(PORT);

  if (-1 == bind(serversock, (struct sockaddr *)&serveraddr, 
                 sizeof(struct sockaddr_in))) 
    perror("Bind");

  if (-1 == listen(serversock, SOMAXCONN))
    perror("Listen");

  FD_ZERO(&fds);
  FD_SET(serversock, &fds);

  while(1) {

    readfds = fds;
    rc = select(FD_SETSIZE, &readfds, NULL, NULL, NULL);

    if (rc == -1) {
      perror("Select");
      break;
    }

    for (i = 0; i < FD_SETSIZE; i++) {
      if (FD_ISSET(i, &readfds)) {
        if (i == serversock) {
          if (numsocks < maxsocks) {
            clientsock[numsocks] = accept(serversock,
                                      (struct sockaddr *) &clientaddr,
                                      (socklen_t *)&clientaddrlen);
            if (clientsock[numsocks] == -1) perror("Accept");
            FD_SET(clientsock[numsocks], &fds);
            numsocks++;
          } else {
            printf("Ran out of socket space.\n");

          }
        } else {
         /* int messageLength = 5;
          char message[messageLength+1];
          int in, index = 0, limit = messageLength+1;

          while ((in = recv(clientsock[i], &message[index], limit, 0)) > 0) {
            index += in;
            limit -= in;
          }

          printf("%d\n", index);
          printf("%s\n", message);*/
          
          bzero(buf, sizeof(buf));
                    if ((rval = read(i, buf, 1024)) < 0)
                        perror("reading stream message");
                    else if (rval == 0)
                        printf("Ending connection\n");
                    else
                        printf("-->%s\n", buf);

        }
      }
    }
  }

  close(serversock);
  return 0;
}
