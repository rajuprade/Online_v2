#include<stdio.h> 
#include<math.h>
#include<string.h>
#include<time.h>
#include<malloc.h>
#include<pthread.h>
//#include<ctime.h>
typedef struct 
{
  int seq;
  char timestamp[64];
  char system_name[16]; // Not required in servo communication
 // char cmd_code[4];
  char op_name[16];
  short int number_param;
  char para_name[32][16];
  char para_value[32][16];
 // // Not required in servo communication
 } servocmd;

void printservocmd(servocmd *c1);

void printservocmd(servocmd *c1)
{
   int i;
        printf("we wrote on the socket %d %s %s %s\n",c1->seq,c1->timestamp,c1->system_name,c1->op_name);
       
        for(i=0;i<c1->number_param;i++)
        {
          printf("%s %s\n",c1->para_name[i],c1->para_value[i]);
        } 
        printf(" Size of Struct is ######## %d\n",sizeof(servocmd));
     
}

void *servo(void* parameters)
{
   fprintf(stderr,"In SERVO function\n"); 
  servocmd *s1;
  s1 = malloc(sizeof(servocmd));
  s1 = (servocmd *)parameters;
  //memcpy(s1,(servocmd *)parameters,sizeof(servocmd));
  //fprintf(stderr,"********** %s\n",s1->op_name); 
  printservocmd(s1);
 // printservocmd((servocmd *)parameters);
  /* while(1)
  {
    Run();
    sleep(5);
   
  } */
 } 

int main()
{
  servocmd *a1;
  a1 = malloc(sizeof(servocmd));

  pthread_t servo_th;
  a1->seq= 11;
  strcpy(a1->system_name,"servo"); 
  strcpy(a1->op_name,"track"); 
  //  sprintf(a1->SRVCMD.SRVCMD_code,"%s","0x44");// Command ID 44
  a1->number_param=4;
  strcpy(a1->para_name[0],"ax");
  strcpy(a1->para_value[0],"B");
                  
                   strcpy(a1->para_name[1],"time"); // Duration for tracking the source
                   strcpy(a1->para_value[1],"12:00:00");
                  
                   strcpy(a1->para_name[2],"ang1");
                   strcpy(a1->para_value[2],"90:00:00");
                   strcpy(a1->para_name[3],"ang2");
                   strcpy(a1->para_value[3],"45:00:00");
                   //fprintf(stderr,"********** %s\n",a1->SRVCMD.op_name);   
		//printservocmd(a1);
  pthread_create(&servo_th,NULL,&servo,(void *)a1);
  pthread_join(servo_th,NULL); 
 return 0;
}
