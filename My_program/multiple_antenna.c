#include<stdio.h>
#include<string.h>

typedef enum { C00,C01,C02,C03,C04,END } ant_name;
int main()
{
  char *antn[]= {"C00","C01","C02","C03","C04"};
  char buf[80];
  
  fgets(buf,80,stdin);
  fprintf(stderr,"User input %s\n",buf);
  
