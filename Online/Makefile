INCLUDEDIR	=-I /usr/include/libxml2 
CFLAGS          = -Wall -g ${INCLUDEDIR} -I. 
LIBS= -lxml2 -lm -lpthread -lreadline
LIBXML=-L/usr/include/libxml2 
LIBS0=${LIBS} ${LIBXML} 

online_v2: main.o system.o shared_mem.o xml.o mcm_thread.o user_info.o socket.o high_user.o queue.o common.o gui.o servo.o servo_queue.o ssclink.o trackservo.o das.o pyenv.o mcm.o fps.o
	gcc $(CFLAGS) $(LIBXMl) -o online_v2 main.o system.o shared_mem.o xml.o mcm_thread.o common.o user_info.o socket.o high_user.o queue.o gui.o servo.o servo_queue.o ssclink.o trackservo.o das.o pyenv.o mcm.o fps.o $(LIBS)

   
main.o: main.c system.o shared_mem.o xml.o mcm_thread.o user_info.o socket.o high_user.o queue.o common.o gui.o servo.o 	servo_queue.o ssclink.o trackservo.o das.o pyenv.o mcm.o fps.o
	gcc $(CFLAGS)  -c main.c 

system.o: system.c system.h
	gcc $(CFLAGS) -c system.c 

shared_mem.o: shared_mem.c server.h
	gcc $(CFLAGS) -c shared_mem.c 

xml.o: xml.c server.h
	gcc $(CFLAGS) -c xml.c 

mcm_thread.o: mcm_thread.c mcm_thread.h
	gcc $(CFLAGS) -c mcm_thread.c 

common.o: common.c server.h
	gcc $(CFLAGS) -c common.c 
user_info.o: user_info.c server.h
	gcc $(CFLAGS) -c user_info.c 

socket.o: socket.c socket.h
	gcc $(CFLAGS) -c socket.c   

high_user.o: high_user.c high_user.h
	gcc $(CFLAGS) -c high_user.c 

queue.o: queue.c queue.h
	gcc $(CFLAGS) -c queue.c 

gui.o: gui.c gui.h
	gcc $(CFLAGS) -c gui.c  

servo.o: servo.c servo.h
	gcc $(CFLAGS) -c servo.c  

servo_queue.o: servo_queue.c servo_queue.h
	gcc $(CFLAGS) -c servo_queue.c  

ssclink.o: ssclink.c ssclink.h
	gcc $(CFLAGS) -c ssclink.c 

trackservo.o: trackservo.c trackservo.h
	gcc $(CFLAGS) -c trackservo.c 

das.o: das.c das.h
	gcc $(CFLAGS) -c das.c

pyenv.o: pyenv.c pyenv.h
	gcc $(CFLAGS) -c pyenv.c 

mcm.o: mcm.c mcm.h
	gcc $(CFLAGS) -c mcm.c 

fps.o: fps.c fps.h
	gcc $(CFLAGS) -c fps.c                         
clean: 
	rm -f  *.o online_v2     
