#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
      char *del = " ",*token, *buf;
      buf = malloc(100);
      char cmd[10][10];
      int i=0;
   
       while(1)
       {
         fprintf(stderr,"Enter the command >> ");
         fgets(buf,100,stdin);
         fprintf(stderr," ######### %s Entered command\n",buf);
    
      
         token=strtok(buf,del);
         while(token !=NULL)
          { 
            strcpy(cmd[i],token);
            fprintf(stderr," CMD[%d] => %s\n",i,cmd[i]);
            i++; 
            token =  strtok(NULL," ");
          }
       } 
return 0;
}
