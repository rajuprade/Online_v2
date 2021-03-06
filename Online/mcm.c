#include"server.h"
#include"mcm.h"
#include"mcm_thread.h"
#include"socket.h"

void* mcmsystem(void* parameters)
{
     //int i;
     pthread_t sen_th,C01_sen_th,C02_sen_th,C03_sen_th,C04_sen_th,C05_sen_th,C06_sen_th,C09_sen_th,C08_sen_th
               ,C10_sen_th,C11_sen_th,C12_sen_th,C13_sen_th,C14_sen_th,E02_sen_th,E03_sen_th,E04_sen_th,E05_sen_th
                 ,E06_sen_th,S01_sen_th,S02_sen_th,S03_sen_th,S04_sen_th,S06_sen_th,W01_sen_th,W02_sen_th
                  ,W03_sen_th,W04_sen_th,W05_sen_th,W06_sen_th;
     
     pthread_t fps_th,C01_fps_th,C02_fps_th,C03_fps_th,C04_fps_th,C05_fps_th,C06_fps_th,C09_fps_th,C08_fps_th
               ,C10_fps_th,C11_fps_th,C12_fps_th,C13_fps_th,C14_fps_th,E02_fps_th,E03_fps_th,E04_fps_th,E05_fps_th
                 ,E06_fps_th,S01_fps_th,S02_fps_th,S03_fps_th,S04_fps_th,S06_fps_th,W01_fps_th,W02_fps_th
                  ,W03_fps_th,W04_fps_th,W05_fps_th,W06_fps_th;     

     pthread_t fiber_th,C01_fiber_th,C02_fiber_th,C03_fiber_th,C04_fiber_th,C05_fiber_th,C06_fiber_th,C09_fiber_th,
               C08_fiber_th,C10_fiber_th,C11_fiber_th,C12_fiber_th,C13_fiber_th,C14_fiber_th,E02_fiber_th,
               E03_fiber_th,E04_fiber_th,E05_fiber_th,E06_fiber_th,S01_fiber_th,S02_fiber_th,S03_fiber_th,S04_fiber_th
              ,S06_fiber_th,W01_fiber_th,W02_fiber_th,W03_fiber_th,W04_fiber_th,W05_fiber_th,W06_fiber_th; 

     pthread_t front_th,C01_front_th,C02_front_th,C03_front_th,C04_front_th,C05_front_th,C06_front_th,C09_front_th,
               C08_front_th,C10_front_th,C11_front_th,C12_front_th,C13_front_th,C14_front_th,E02_front_th,E03_front_th,
               E04_front_th,E05_front_th,E06_front_th,S01_front_th,S02_front_th,S03_front_th,S04_front_th,
               S06_front_th,W01_front_th,W02_front_th,W03_front_th,W04_front_th,W05_front_th,W06_front_th; 

     pthread_t backend_th,C01_backend_th,C02_backend_th,C03_backend_th,C04_backend_th,C05_backend_th,C06_backend_th
                ,C09_backend_th,C08_backend_th,C10_backend_th,C11_backend_th,C12_backend_th,
                 C13_backend_th,C14_backend_th,E02_backend_th,E03_backend_th,E04_backend_th,E05_backend_th
                 ,E06_backend_th,S01_backend_th,S02_backend_th,S03_backend_th,S04_backend_th,S06_backend_th,
                  W01_backend_th,W02_backend_th
                  ,W03_backend_th,W04_backend_th,W05_backend_th,W06_backend_th;


     pthread_t self_th,C01_self_th,C02_self_th,C03_self_th,C04_self_th,C05_self_th,C06_self_th,C09_self_th,C08_self_th
                ,C10_self_th,C11_self_th,C12_self_th,C13_self_th,C14_self_th,E02_self_th,E03_self_th,E04_self_th,E05_self_th
                 ,E06_self_th,S01_self_th,S02_self_th,S03_self_th,S04_self_th,S06_self_th,W01_self_th,W02_self_th
                  ,W03_self_th,W04_self_th,W05_self_th,W06_self_th;

      pthread_attr_t attrs;
      pthread_attr_init(&attrs);
      pthread_attr_setstacksize(&attrs,THREAD_STACK_SZ);

     pthread_attr_t custom_attr_fifo;	
     //int fifo_max_prio;	
     struct sched_param fifo_param;	
      int server_fd, *new_sock,Ret,sockfd;
      pthread_mutex_init(&lock,NULL);
   
    pthread_attr_init(&custom_attr_fifo);	
    pthread_attr_setschedpolicy(&custom_attr_fifo, SCHED_FIFO);	
    fifo_param.sched_priority = sched_get_priority_max(SCHED_FIFO);	
    pthread_attr_setschedparam(&custom_attr_fifo, &fifo_param); 
	
     sockfd=init_server(PORT);
     if(sockfd == -1)
     {
       fprintf(stderr," ####### MAIN SERVER FAILS ##########\n");
     }
    clilen = sizeof(cli_addr); 
        while(1)
       {  
           // i=0;
            fprintf(stderr,"############# SERVER WANTING FOR CLIENT CONNECTION #####\n");
            server_fd = accept(sockfd,(struct sockaddr *) &cli_addr,&clilen); 
            if(!strcmp(inet_ntoa(cli_addr.sin_addr),SENTINEL_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&sen_th,&attrs,&sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SENTINEL thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"SENTINEL thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),FIBER_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&fiber_th,&attrs,&fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening FIBER thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"FIBER thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&fps_th,&attrs,&fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&front_th,&attrs,&front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening FRONT thread %d\n",Ret);
                             handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"FRONT thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&backend_th,&attrs,&backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening BACKEND thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"BACKEND thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&self_th,&attrs,&self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C01_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_sen_th,&attrs,&C01_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C01 Sentinel thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C01 SENTINEL thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C01_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_fps_th,&attrs,&C01_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C01 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C01 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C01_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_front_th,&attrs,&C01_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C01 FRONT thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C01 FRONT END thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C01_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_fiber_th,&attrs,&C01_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C01 OF thread %d\n",Ret);
                                handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C01 OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C01_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_backend_th,&attrs,&C01_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C01 BE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C01 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C01_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_self_th,&attrs,&C01_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C01 SELF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C01 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                       else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C02_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C02_sen_th,&attrs,&C02_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C02 SEN thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"SENTINEL C02 thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C02_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C02_fps_th,&attrs,&C02_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C02 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C02 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C02_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C02_front_th,&attrs,&C02_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C02 FE thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C02 FRS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C02_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C02_fiber_th,&attrs,&C02_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C02 OF thread %d\n",Ret);
                                handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C02 Fiber thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C02_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C02_backend_th,&attrs,&C02_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C02 BE thread %d\n",Ret);
                                handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C02 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C02_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C02_self_th,&attrs,&C02_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C02 SELF thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C02 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C03_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C03_sen_th,&attrs,&C03_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C03 SEN thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C03 SEN thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C03_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C03_fps_th,&attrs,&C03_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C03 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C03 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C03_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C03_front_th,&attrs,&C03_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C03 FE thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C03 FE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C03_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C03_fiber_th,&attrs,&C03_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C03 OF thread %d\n",Ret);
                                handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C03 OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C03_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C03_backend_th,&attrs,&C03_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C03 BE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C03 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C03_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C03_self_th,&attrs,&C03_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C03 SELF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C03 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                       else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C04_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C04_sen_th,&attrs,&C04_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C04 SEN thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C04 SEN thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C04_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C04_fps_th,&attrs,&C04_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C04 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C04 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C04_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C04_front_th,&attrs,&C04_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C04 FE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C04 FE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C04_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_fiber_th,&attrs,&C04_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C04 OF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C04 OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C04_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C04_backend_th,&attrs,&C04_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C04 BE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C04 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C04_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C04_self_th,&attrs,&C04_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C04 SELF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C04 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                       else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C05_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C05_sen_th,&attrs,&C05_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C05 SEN thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C05 SEN thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C05_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C05_fps_th,&attrs,&C05_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C05 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C05 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C05_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C05_front_th,&attrs,&C05_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C05 FE thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C05 FE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C05_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C05_fiber_th,&attrs,&C05_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C05 OF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C05 OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C05_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C05_backend_th,&attrs,&C05_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C05 BE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C05 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C05_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C05_self_th,&attrs,&C05_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C05 SELF thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C05 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                      }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C06_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C06_sen_th,&attrs,&C06_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C06 SEN thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C06 SEN thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C06_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM C06 FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C06_fps_th,&attrs,&C06_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C06 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C06 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C06_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C06_front_th,&attrs,&C06_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C06 FE thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C06 FE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C06_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C01_fiber_th,&attrs,&C06_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C06 OF thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C06 OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C06_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C06_backend_th,&attrs,&C06_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C06 BE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C06 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C06_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C06_self_th,&attrs,&C06_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C06 SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C06 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                      }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C08_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C08_sen_th,&attrs,&C08_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C08 SEN thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C08 SEN thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C08_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C08_fps_th,&attrs,&C08_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C08 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C08 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C08_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C08_front_th,&attrs,&C08_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C08 FE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C08 FE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C08_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C08_fiber_th,&attrs,&C08_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C08 OF thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C08 OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C08_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C08_backend_th,&attrs,&C08_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C08 BE thread %d\n",Ret);
                              handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C08 BE thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C08_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C08_self_th,&attrs,&C08_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C08 SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C08 SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C09_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C09_sen_th,&attrs,&C09_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C09 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C09_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C09_fps_th,&attrs,&C09_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C09 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C09 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C09_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C09_front_th,&attrs,&C09_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C09_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C09_fiber_th,&attrs,&C09_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C09_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C09_backend_th,&attrs,&C09_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C09_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C09_self_th,NULL,&C09_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                          }
                        }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C10_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C10_sen_th,&attrs,&C10_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C10 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C10_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C10_fps_th,&attrs,&C10_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C10 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C10 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C10_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C10_front_th,&attrs,&C10_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C10_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C10_fiber_th,&attrs,&C10_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C10_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C10_backend_th,&attrs,&C10_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C10_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C10_self_th,NULL,&C10_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     } 
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C11_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C11_sen_th,&attrs,&C11_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C11 sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C11_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C11_fps_th,&attrs,&C11_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C11 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C11 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C11_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C11_front_th,&attrs,&C11_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C11_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C11_fiber_th,&attrs,&C11_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C11_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C11_backend_th,&attrs,&C11_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C11_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C11_self_th,NULL,&C11_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C12_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C12_sen_th,&attrs,&C12_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C12 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C12_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C12_fps_th,&attrs,&C12_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C12 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C12 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C12_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C12_front_th,&attrs,&C12_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C12_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C12_fiber_th,&attrs,&C12_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C12_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C12_backend_th,&attrs,&C12_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C12_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C12_self_th,NULL,&C12_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C13_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C13_sen_th,&attrs,&C13_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C13 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C13_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C13_fps_th,&attrs,&C13_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C13 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C13 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C13_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C13_front_th,&attrs,&C13_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C13_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C13_fiber_th,&attrs,&C13_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C13_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C13_backend_th,&attrs,&C13_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C13_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C13_self_th,NULL,&C13_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C14_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C14_sen_th,&attrs,&C14_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"C14 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C14_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C14_fps_th,&attrs,&C14_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening C14 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"C14 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C14_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C14_front_th,&attrs,&C14_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C14_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C14_fiber_th,&attrs,&C14_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C14_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C14_backend_th,&attrs,&C14_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),C14_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&C14_self_th,NULL,&C14_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E02_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E02_sen_th,&attrs,&E02_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"E02 thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E02_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E02_fps_th,&attrs,&E02_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening E02 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"E02 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E02_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E02_front_th,&attrs,&E02_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E02_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E02_fiber_th,&attrs,&E02_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E02_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E02_backend_th,&attrs,&E02_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E02_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E02_self_th,NULL,&E02_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                       else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E03_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E03_sen_th,&attrs,&E03_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"E03 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E03_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E03_fps_th,&attrs,&E03_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening E03 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"E03 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E03_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E03_front_th,&attrs,&E03_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E03_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E03_fiber_th,&attrs,&E03_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E03_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E03_backend_th,&attrs,&E03_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E03_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E03_self_th,NULL,&E03_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E04_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E04_sen_th,&attrs,&E04_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"E04 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E04_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E04_fps_th,&attrs,&E04_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening E04 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"E04 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E04_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E04_front_th,&attrs,&E04_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E04_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E04_fiber_th,&attrs,&E04_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E04_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E04_backend_th,&attrs,&E04_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E04_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E04_self_th,NULL,&E04_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E05_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E05_sen_th,&attrs,&E05_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"E05 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E05_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E05_fps_th,&attrs,&E05_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening E05 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"E05 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E05_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E05_front_th,&attrs,&E05_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E05_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E05_fiber_th,&attrs,&E05_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E05_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E05_backend_th,&attrs,&E05_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E05_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E05_self_th,NULL,&E05_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E06_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E06_sen_th,&attrs,&E06_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"E06 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E06_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E06_fps_th,&attrs,&E06_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening E06 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"E06 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E06_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E06_front_th,&attrs,&E06_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E06_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E06_fiber_th,&attrs,&E06_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E06_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E06_backend_th,&attrs,&E06_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),E06_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&E06_self_th,NULL,&E06_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S01_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S01_sen_th,&attrs,&S01_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"S01 sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S01_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S01_fps_th,&attrs,&S01_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening S01 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"S01 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S01_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S01_front_th,&attrs,&S01_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S01_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S01_fiber_th,&attrs,&S01_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S01_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S01_backend_th,&attrs,&S01_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S01_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S01_self_th,NULL,&S01_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S02_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S02_sen_th,&attrs,&S02_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"S02 Sentinel succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S02_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S02_fps_th,&attrs,&S02_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening S02 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"S02 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S02_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S02_front_th,&attrs,&S02_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S02_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S02_fiber_th,&attrs,&S02_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S02_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S02_backend_th,&attrs,&S02_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S02_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S02_self_th,NULL,&S02_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S03_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S03_sen_th,&attrs,&S03_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"S03 Sentinel succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S03_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S03_fps_th,&attrs,&S03_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening S03 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"S03 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S03_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S03_front_th,&attrs,&S03_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S03_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S03_fiber_th,&attrs,&S03_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S03_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S03_backend_th,&attrs,&S03_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S03_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S03_self_th,NULL,&S03_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S04_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S04_sen_th,&attrs,&S04_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"S04 sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S04_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S04_fps_th,&attrs,&S04_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening S04 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"S04 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S04_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S04_front_th,&attrs,&S04_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S04_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S04_fiber_th,&attrs,&S04_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S04_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S04_backend_th,&attrs,&S04_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S04_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S04_self_th,NULL,&S04_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S06_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S06_sen_th,&attrs,&S06_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"S06 sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S06_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S06_fps_th,&attrs,&S06_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening S06 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"S06 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S06_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S06_front_th,&attrs,&S06_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S06_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S06_fiber_th,&attrs,&S06_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S06_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S06_backend_th,&attrs,&S06_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),S06_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&S06_self_th,NULL,&S06_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                        else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W01_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W01_sen_th,&attrs,&W01_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"W01 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W01_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W01_fps_th,&attrs,&W01_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening W01 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"W01 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W01_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W01_front_th,&attrs,&W01_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W01_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W01_fiber_th,&attrs,&W01_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W01_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W01_backend_th,&attrs,&W01_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W01_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W01_self_th,NULL,&W01_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W02_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W02_sen_th,&attrs,&W02_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr," W02 sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W02_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W02_fps_th,&attrs,&W02_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening W02 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"W02 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W02_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W02_front_th,&attrs,&W02_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W02_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W02_fiber_th,&attrs,&W02_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W02_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W02_backend_th,&attrs,&W02_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W02_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W02_self_th,NULL,&W02_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W03_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W03_sen_th,&attrs,&W03_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr," W03 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W03_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W03_fps_th,&attrs,&W03_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening W03 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"W03 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W03_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W03_front_th,&attrs,&W03_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W03_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W03_fiber_th,&attrs,&W03_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W03_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W03_backend_th,&attrs,&W03_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W03_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W03_self_th,NULL,&W03_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W04_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W04_sen_th,&attrs,&W04_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr," W04 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W04_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W04_fps_th,&attrs,&W04_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening W04 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"W04 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W04_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W04_front_th,&attrs,&W04_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W04_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W04_fiber_th,&attrs,&W04_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W04_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W04_backend_th,&attrs,&W04_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W04_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W04_self_th,NULL,&W04_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W05_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W05_sen_th,&attrs,&W05_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"W05 Sen/OF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W05_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W05_fps_th,&attrs,&W05_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening W05 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"W05 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W05_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W05_front_th,&attrs,&W05_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W05_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W05_fiber_th,&attrs,&W05_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W05_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W05_backend_th,&attrs,&W05_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W05_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W05_self_th,NULL,&W05_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                         else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W06_SENTINEL_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W06_sen_th,&attrs,&W06_sentinel_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"W06 Sentinel thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                      else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W06_FPS_IP))
                     { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM FPS MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W06_fps_th,&attrs,&W06_fps_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening W06 FPS thread %d\n",Ret);
                               handle_error_en(Ret, "pthread_create");
                           }
                          else 
                          {
                            fprintf(stderr,"W06 FPS thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W06_FRONT_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W06_front_th,&attrs,&W06_front_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W06_FIBER_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W06_fiber_th,&attrs,&W06_fiber_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W06_BACKEND_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W06_backend_th,&attrs,&W06_backend_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                     }
                     else if(!strcmp(inet_ntoa(cli_addr.sin_addr),W06_SELF_IP))
                      { 
                        new_sock = malloc(1);
                        *new_sock = server_fd;
                        fprintf(stderr," ACCEPTED CONNECTION FROM MCM DEVICE %s\n",inet_ntoa(cli_addr.sin_addr));
                         Ret= pthread_create(&W06_self_th,NULL,&W06_self_thread,(void *)new_sock); 
                          if(Ret)
                           { 
                             fprintf(stderr,"Error in Opening SELF thread %d\n",Ret);
                           }
                          else 
                          {
                            fprintf(stderr,"SELF thread opened succesfully=> %d\n",Ret); 
                         }
                       }
                     else
                     { fprintf(stderr,"######### NOT AUTHORIZED IP ##########\n"); }
         
         // i++;
         }  
  pthread_join(sen_th,NULL); 
  pthread_join(fiber_th,NULL);
  pthread_join(front_th,NULL);
  pthread_join(backend_th,NULL);
  pthread_join(self_th,NULL);
  pthread_join(fps_th,NULL);
  pthread_join(C01_sen_th,NULL); 
  pthread_join(C01_fiber_th,NULL);
  pthread_join(C01_front_th,NULL);
  pthread_join(C01_backend_th,NULL);
  pthread_join(C01_self_th,NULL);
  pthread_join(C01_fps_th,NULL);
  pthread_join(C02_sen_th,NULL); 
  pthread_join(C02_fiber_th,NULL);
  pthread_join(C02_front_th,NULL);
  pthread_join(C02_backend_th,NULL);
  pthread_join(C02_fps_th,NULL);
  pthread_join(C02_self_th,NULL);
  pthread_join(C03_sen_th,NULL); 
  pthread_join(C03_fiber_th,NULL);
  pthread_join(C03_front_th,NULL);
  pthread_join(C03_fps_th,NULL);
  pthread_join(C03_backend_th,NULL);
  pthread_join(C03_self_th,NULL);
  pthread_join(C04_sen_th,NULL);
  pthread_join(C04_fps_th,NULL); 
  pthread_join(C04_fiber_th,NULL);
  pthread_join(C04_front_th,NULL);
  pthread_join(C04_backend_th,NULL);
  pthread_join(C04_self_th,NULL);
  pthread_join(C05_sen_th,NULL);
  pthread_join(C05_fps_th,NULL); 
  pthread_join(C05_fiber_th,NULL);
  pthread_join(C05_front_th,NULL);
  pthread_join(C05_backend_th,NULL);
  pthread_join(C05_self_th,NULL);
  pthread_join(C06_sen_th,NULL);
  pthread_join(C06_fps_th,NULL); 
  pthread_join(C06_fiber_th,NULL);
  pthread_join(C06_front_th,NULL);
  pthread_join(C06_backend_th,NULL);
  pthread_join(C06_self_th,NULL);
  pthread_join(C09_sen_th,NULL); 
  pthread_join(C09_fps_th,NULL);
  pthread_join(C09_fiber_th,NULL);
  pthread_join(C09_front_th,NULL);
  pthread_join(C09_backend_th,NULL);
  pthread_join(C09_self_th,NULL);
  pthread_join(C08_sen_th,NULL); 
  pthread_join(C08_fps_th,NULL);
  pthread_join(C08_fiber_th,NULL);
  pthread_join(C08_front_th,NULL);
  pthread_join(C08_backend_th,NULL);
  pthread_join(C08_self_th,NULL);
  pthread_join(C10_sen_th,NULL); 
  pthread_join(C10_fps_th,NULL);
  pthread_join(C10_fiber_th,NULL);
  pthread_join(C10_front_th,NULL);
  pthread_join(C10_backend_th,NULL);
  pthread_join(C10_self_th,NULL);
  pthread_join(C11_sen_th,NULL); 
  pthread_join(C11_fps_th,NULL);
  pthread_join(C11_fiber_th,NULL);
  pthread_join(C11_front_th,NULL);
  pthread_join(C11_backend_th,NULL);
  pthread_join(C11_self_th,NULL);
  pthread_join(C12_sen_th,NULL); 
  pthread_join(C12_fps_th,NULL);
  pthread_join(C12_fiber_th,NULL);
  pthread_join(C12_front_th,NULL);
  pthread_join(C12_backend_th,NULL);
  pthread_join(C12_self_th,NULL);
  pthread_join(C13_sen_th,NULL); 
  pthread_join(C13_fps_th,NULL);
  pthread_join(C13_fiber_th,NULL);
  pthread_join(C13_front_th,NULL);
  pthread_join(C13_backend_th,NULL);
  pthread_join(C13_self_th,NULL);
  pthread_join(C14_sen_th,NULL); 
  pthread_join(C14_fps_th,NULL);
  pthread_join(C14_fiber_th,NULL);
  pthread_join(C14_front_th,NULL);
  pthread_join(C14_backend_th,NULL);
  pthread_join(C14_self_th,NULL);
  pthread_join(E02_sen_th,NULL); 
  pthread_join(E02_fps_th,NULL);
  pthread_join(E02_fiber_th,NULL);
  pthread_join(E02_front_th,NULL);
  pthread_join(E02_backend_th,NULL);
  pthread_join(E02_self_th,NULL);
  pthread_join(E03_sen_th,NULL); 
  pthread_join(E03_fps_th,NULL);
  pthread_join(E03_fiber_th,NULL);
  pthread_join(E03_front_th,NULL);
  pthread_join(E03_backend_th,NULL);
  pthread_join(E03_self_th,NULL);
  pthread_join(E04_sen_th,NULL); 
  pthread_join(E04_fps_th,NULL);
  pthread_join(E04_fiber_th,NULL);
  pthread_join(E04_front_th,NULL);
  pthread_join(E04_backend_th,NULL);
  pthread_join(E04_self_th,NULL);
  pthread_join(E05_sen_th,NULL); 
  pthread_join(E05_fps_th,NULL);
  pthread_join(E05_fiber_th,NULL);
  pthread_join(E05_front_th,NULL);
  pthread_join(E05_backend_th,NULL);
  pthread_join(E05_self_th,NULL);
  pthread_join(E06_sen_th,NULL); 
  pthread_join(E06_fps_th,NULL);
  pthread_join(E06_fiber_th,NULL);
  pthread_join(E06_front_th,NULL);
  pthread_join(E06_backend_th,NULL);
  pthread_join(E06_self_th,NULL);
  pthread_join(S01_sen_th,NULL); 
  pthread_join(S01_fps_th,NULL);
  pthread_join(S01_fiber_th,NULL);
  pthread_join(S01_front_th,NULL);
  pthread_join(S01_backend_th,NULL);
  pthread_join(S01_self_th,NULL);
  pthread_join(S02_sen_th,NULL); 
  pthread_join(S02_fps_th,NULL);
  pthread_join(S02_fiber_th,NULL);
  pthread_join(S02_front_th,NULL);
  pthread_join(S02_backend_th,NULL);
  pthread_join(S02_self_th,NULL);
  pthread_join(S03_sen_th,NULL); 
  pthread_join(S03_fps_th,NULL);
  pthread_join(S03_fiber_th,NULL);
  pthread_join(S03_front_th,NULL);
  pthread_join(S03_backend_th,NULL);
  pthread_join(S03_self_th,NULL);
  pthread_join(S04_sen_th,NULL); 
  pthread_join(S04_fps_th,NULL);
  pthread_join(S04_fiber_th,NULL);
  pthread_join(S04_front_th,NULL);
  pthread_join(S04_backend_th,NULL);
  pthread_join(S04_self_th,NULL);
  pthread_join(S06_sen_th,NULL); 
  pthread_join(S06_fps_th,NULL);
  pthread_join(S06_fiber_th,NULL);
  pthread_join(S06_front_th,NULL);
  pthread_join(S06_backend_th,NULL);
  pthread_join(S06_self_th,NULL);
  pthread_join(W01_sen_th,NULL); 
  pthread_join(W01_fps_th,NULL);
  pthread_join(W01_fiber_th,NULL);
  pthread_join(W01_front_th,NULL);
  pthread_join(W01_backend_th,NULL);
  pthread_join(W01_self_th,NULL);
  pthread_join(W02_sen_th,NULL); 
  pthread_join(W02_fps_th,NULL);
  pthread_join(W02_fiber_th,NULL);
  pthread_join(W02_front_th,NULL);
  pthread_join(W02_backend_th,NULL);
  pthread_join(W02_self_th,NULL);
  pthread_join(W03_sen_th,NULL); 
  pthread_join(W03_fps_th,NULL);
  pthread_join(W03_fiber_th,NULL);
  pthread_join(W03_front_th,NULL);
  pthread_join(W03_backend_th,NULL);
  pthread_join(W03_self_th,NULL);
  pthread_join(W04_sen_th,NULL); 
  pthread_join(W04_fps_th,NULL);
  pthread_join(W04_fiber_th,NULL);
  pthread_join(W04_front_th,NULL);
  pthread_join(W04_backend_th,NULL);
  pthread_join(W04_self_th,NULL);
  pthread_join(W05_sen_th,NULL); 
  pthread_join(W05_fps_th,NULL);
  pthread_join(W05_fiber_th,NULL);
  pthread_join(W05_front_th,NULL);
  pthread_join(W05_backend_th,NULL);
  pthread_join(W05_self_th,NULL);
  pthread_join(W06_sen_th,NULL); 
  pthread_join(W06_fps_th,NULL);
  pthread_join(W06_fiber_th,NULL);
  pthread_join(W06_front_th,NULL);
  pthread_join(W06_backend_th,NULL);
  pthread_join(W06_self_th,NULL);
  pthread_mutex_destroy(&lock);    
    
}
   
        
