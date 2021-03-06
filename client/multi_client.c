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
#define SERVER_IP "192.168.8.45"

int main(int argc, char **argv) {

  struct sockaddr_in servaddr;
  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (sock == -1) perror("Socket");

  bzero((void *) &servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

  if (-1 == connect(sock, (struct sockaddr *)&servaddr, sizeof(servaddr)))
    perror("Connect");

  while(1) {

    char message[6];
    fgets(message, 6, stdin);

    message[5] = '\0';

    send(sock, message, 6, 0);
  }


  close(sock);
}
