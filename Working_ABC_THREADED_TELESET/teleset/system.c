
#include"server.h"
/******* Sentinel *******/
void sentinel(ANT_CMD *a1)
{
   int op;
 /*  char *tstamp;
   tstamp = malloc(25);
   tstamp = tp(tstamp);
   strcpy(a1->CMD[0]->timestamp,tstamp);*/
  // strcpy(a1->CMD[0]->timestamp,stamp1);
   strcpy(a1->CMD[0].system_name,"sentinel");
    printf(" Enter operation number 0:mon 1:set 2:init 3:reset\n");
    scanf("%d",&op);
    switch(op)
    {
      case 0:  a1->CMD[0].seq= 10;
               strcpy( a1->CMD[0].op_name,"mon");
               a1->CMD[0].number_param=0;
               break;
      case 1:  a1->CMD[0].seq= 11;
               strcpy(a1->CMD[0].op_name,"set");
               a1->CMD[0].number_param=1;
               strcpy(a1->CMD[0].parameter_name[0],"dmask");
               strcpy(a1->CMD[0].Argument_Ch1[0],"ffff");
               strcpy(a1->CMD[0].Argument_Ch2[0],"5555"); 
               break;
      case 2:  a1->CMD[0].seq= 12;
               strcpy(a1->CMD[0].op_name,"init");
               a1->CMD[0].number_param=0;
               break;
      case 3:  a1->CMD[0].seq= 13;
               strcpy(a1->CMD[0].op_name,"reset");
               a1->CMD[0].number_param=0;
               break;   
    }
     
}

/*********** sentinel ******/


/******* fiber_optics *******/
void fiber_optics(ANT_CMD *a1)
{
   int op;
 /*  time_t t1;
   char stamp1[26];
   time(&t1);
   ctime_r(&t1,stamp1);
   strcpy(a1->CMD[0]->timestamp,stamp1); */
  /*  char *tstamp;
   tstamp = malloc(25);
   tstamp = tp(tstamp);
   strcpy(a1->CMD[0]->timestamp,tstamp);*/
   strcpy(a1->CMD[0].system_name,"fiber_optics");

    printf(" Enter operation number 0:mon 1:set 2:init 3:reset\n");
    scanf("%d",&op);
    switch(op)
    {
      case 0:  a1->CMD[0].seq= 10;
               strcpy(a1->CMD[0].op_name,"mon");
               a1->CMD[0].number_param=0;
               break;

      case 1:  a1->CMD[0].seq= 11;
               strcpy(a1->CMD[0].op_name,"set");
               a1->CMD[0].number_param=1;
               strcpy(a1->CMD[0].parameter_name[0],"rf_attn");
               strcpy(a1->CMD[0].Argument_Ch1[0],"25");
               strcpy(a1->CMD[0].Argument_Ch2[0],"35"); 
               break;

      case 2:  a1->CMD[0].seq= 12;
               strcpy(a1->CMD[0].op_name,"init");      
               a1->CMD[0].number_param=0;
               break;

      case 3:  a1->CMD[0].seq= 13;
               strcpy(a1->CMD[0].op_name,"reset");
               a1->CMD[0].number_param=0;
               break;   
    }
     
}

/************** fiber_optics *****/

/******* back_end *******/
void back_end(ANT_CMD *a1)
{
   int op;
 /*  time_t t1;
   char stamp1[26];
   time(&t1);
   ctime_r(&t1,stamp1);
   strcpy(a1->CMD[0]->timestamp,stamp1); */
  /* char *tstamp;
   tstamp = malloc(25);
   tstamp = tp(tstamp);
   strcpy(a1->CMD[0]->timestamp,tstamp);*/
   strcpy(a1->CMD[0].system_name,"back_end");

    printf(" Enter operation number 0:mon 1:set 2:init 3:reset\n");
    scanf("%d",&op);
    switch(op)
    {
      case 0:  a1->CMD[0].seq= 10;
               strcpy(a1->CMD[0].op_name,"mon");
               a1->CMD[0].number_param=0;
               break;

      case 1:  a1->CMD[0].seq= 11;
               strcpy(a1->CMD[0].op_name,"set");
               a1->CMD[0].number_param=8;

                       strcpy(a1->CMD[0].parameter_name[0],"lo");
                       strcpy(a1->CMD[0].parameter_name[1],"attn");
                       strcpy(a1->CMD[0].parameter_name[2],"filter");
                       strcpy(a1->CMD[0].parameter_name[3],"lpf");
                       strcpy(a1->CMD[0].parameter_name[4],"source");
                       strcpy(a1->CMD[0].parameter_name[5],"ant_ns");
                       strcpy(a1->CMD[0].parameter_name[6],"drct_mxr");
                       strcpy(a1->CMD[0].parameter_name[7],"channel");

                       strcpy(a1->CMD[0].Argument_Ch1[0],"1600000");
                       strcpy(a1->CMD[0].Argument_Ch1[1],"10");
                       strcpy(a1->CMD[0].Argument_Ch1[2],"8");
                       strcpy(a1->CMD[0].Argument_Ch1[3],"0");
                       strcpy(a1->CMD[0].Argument_Ch1[4],"siggen");
                       strcpy(a1->CMD[0].Argument_Ch1[5],"antenna");
                       strcpy(a1->CMD[0].Argument_Ch1[6],"direct");
                       strcpy(a1->CMD[0].Argument_Ch1[7],"1");
    
                       strcpy(a1->CMD[0].Argument_Ch2[0],"1600000"); 
                       strcpy(a1->CMD[0].Argument_Ch2[1],"12");
                       strcpy(a1->CMD[0].Argument_Ch2[2],"6");
                       strcpy(a1->CMD[0].Argument_Ch2[3],"1");
                       strcpy(a1->CMD[0].Argument_Ch2[4],"synthesizer");
                       strcpy(a1->CMD[0].Argument_Ch2[5],"noise");
                       strcpy(a1->CMD[0].Argument_Ch2[6],"mixer");
                       strcpy(a1->CMD[0].Argument_Ch2[7],"2");
               break;

      case 2:  a1->CMD[0].seq= 12;
               strcpy(a1->CMD[0].op_name,"init");      
               a1->CMD[0].number_param=0;
               break;

      case 3:  a1->CMD[0].seq= 13;
               strcpy(a1->CMD[0].op_name,"reset");
               a1->CMD[0].number_param=0;
               break;   
    }
     
}

/************** back_end *****/

/******* front_end *******/
void front_end(ANT_CMD *a1)
{
   int op;
 /*  time_t t1;
   char stamp1[26];
   time(&t1);
   ctime_r(&t1,stamp1);
   strcpy(a1->CMD[0]->timestamp,stamp1); */
  /*  char *tstamp;
   tstamp = malloc(25);
   tstamp = tp(tstamp);
   strcpy(a1->CMD[0]->timestamp,tstamp);*/
   strcpy(a1->CMD[0].system_name,"front_end");
    printf(" Enter operation number 0:mon 1:set 2:init 3:reset\n");
    scanf("%d",&op);
    switch(op)
    {
      case 0:  a1->CMD[0].seq= 10;
               strcpy(a1->CMD[0].op_name,"mon");
               a1->CMD[0].number_param=0;
               break;

      case 1:  a1->CMD[0].seq= 11;
               strcpy(a1->CMD[0].op_name,"set");
               a1->CMD[0].number_param=7;

                       strcpy(a1->CMD[0].parameter_name[0],"cal_ns");
                       strcpy(a1->CMD[0].parameter_name[1],"rf");
                       strcpy(a1->CMD[0].parameter_name[2],"filter");
                       strcpy(a1->CMD[0].parameter_name[3],"fltr_bnd");
                       strcpy(a1->CMD[0].parameter_name[4],"band_sel");
                       strcpy(a1->CMD[0].parameter_name[5],"slr_attn");
                       strcpy(a1->CMD[0].parameter_name[6],"channel");

                       strcpy(a1->CMD[0].Argument_Ch1[0],"LO");
                       strcpy(a1->CMD[0].Argument_Ch1[1],"on");
                       strcpy(a1->CMD[0].Argument_Ch1[2],"1");
                       strcpy(a1->CMD[0].Argument_Ch1[3],"1060");
                       strcpy(a1->CMD[0].Argument_Ch1[4],"50");
                       strcpy(a1->CMD[0].Argument_Ch1[5],"44");
                       strcpy(a1->CMD[0].Argument_Ch1[6],"swap");
                       
    
                       strcpy(a1->CMD[0].Argument_Ch2[0],"Medium"); 
                       strcpy(a1->CMD[0].Argument_Ch2[1],"off");
                       strcpy(a1->CMD[0].Argument_Ch2[2],"4");
                       strcpy(a1->CMD[0].Argument_Ch2[3],"1170");
                       strcpy(a1->CMD[0].Argument_Ch2[4],"150");
                       strcpy(a1->CMD[0].Argument_Ch2[5],"30");
                       strcpy(a1->CMD[0].Argument_Ch2[6],"unswap");
                      
               break;

      case 2:  a1->CMD[0].seq= 12;
               strcpy(a1->CMD[0].op_name,"init");      
               a1->CMD[0].number_param=0;
               break;

      case 3:  a1->CMD[0].seq= 13;
               strcpy(a1->CMD[0].op_name,"reset");
               a1->CMD[0].number_param=0;
               break;   
    }
     
}

/************** front_end *****/

/***************self_test **********/
void self_test(ANT_CMD *a1)
{
   int op;
 /*  time_t t1;
   char stamp1[26];
   time(&t1);
   ctime_r(&t1,stamp1);
   strcpy(a1->CMD[0]->timestamp,stamp1); */
 /*   char *tstamp;
   tstamp = malloc(25);
   tstamp = tp(tstamp);
   strcpy(a1->CMD[0]->timestamp,tstamp); */
   strcpy(a1->CMD[0].system_name,"self_test");

    printf(" Enter operation number 0:mon 1:set 2:init 3:reset\n");
    scanf("%d",&op);
    switch(op)
    {
      case 0:  a1->CMD[0].seq= 10;
               strcpy(a1->CMD[0].op_name,"mon");
               a1->CMD[0].number_param=0;
               break;

      case 1:  a1->CMD[0].seq= 11;
               strcpy(a1->CMD[0].op_name,"set");
               a1->CMD[0].number_param=3;
               strcpy(a1->CMD[0].parameter_name[0],"ss");// set spectrum spreader
               strcpy(a1->CMD[0].Argument_Ch1[0],"0");   // Range : 0,1,2,3
               strcpy(a1->CMD[0].parameter_name[1],"fdb");// set frequency doubler
               strcpy(a1->CMD[0].Argument_Ch1[1],"1");   // Range 0 or 1 
               strcpy(a1->CMD[0].parameter_name[2],"fdv");// set frequency divider
               strcpy(a1->CMD[0].Argument_Ch1[2],"2");   // Range 1,2,4,6,8   
               break;

      case 2:  a1->CMD[0].seq= 12;
               strcpy(a1->CMD[0].op_name,"init");      
               a1->CMD[0].number_param=0;
               break;

      case 3:  a1->CMD[0].seq= 13;
               strcpy(a1->CMD[0].op_name,"reset");
               a1->CMD[0].number_param=0;
               break;   
    }
     
}


/**************self_test **********/

void exec_cmd(int n,ANT_CMD *a1)
{

   switch(n)
   { 
     case 0:sentinel(a1); break;
     case 1:front_end(a1); break;
     case 2:fiber_optics(a1); break;
     case 3:back_end(a1); break;
     case 4:self_test(a1); break;
     default: break;
   }
}

