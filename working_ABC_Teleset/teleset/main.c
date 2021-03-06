#include"server.h"

#if defined(LIBXML_TREE_ENABLED) && defined(LIBXML_OUTPUT_ENABLED)


int main(int argc, char *argv[])
{
     int n;
     int socfd[30];
     pthread_t first_antenna;
     setdata *set;  
     set = (setdata *)malloc(sizeof(setdata));
      
      ANS *an;
      an = malloc(sizeof(ANS));
     
      printf("Enter 0 for file input and 1 for user input\n");
      scanf("%d",&n);
      exec(set,n);
      write_us_shm(set);

     if(init_server()== ERROR)
     {
       fprintf(stderr," ####### ERROR Opening Socket ##########\n");
     }
    clilen = sizeof(cli_addr); 
        while(1)
       {  
           fprintf(stderr,"############# SERVER WANTING FOR CLIENT CONNECTION #####\n");
           socfd[0] = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen); 
           strcpy(an->aname,set->Tx[0].s_a[0].ant_name[0]); // copy the first antenna name from file/user input
           fprintf(stderr,"######## Number of Antenna in sub array [[[%d]]]\n",set->Tx[0].s_a[0].num_in_sub); 
           an->sockfd=socfd[0];
           if( pthread_create( &first_antenna , NULL ,  connection_handler , (void*) an) < 0)
            {
              perror("could not create thread");
              return 1;
           }
          
         }     
     return 0; 
}
#else
int main(void) {
    fprintf(stderr, "server2 support not compiled in\n");
    exit(1);
}
#endif

