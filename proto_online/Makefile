INCLUDEDIR	=-I /usr/include/libxml2 
CFLAGS          = -Wall -g ${INCLUDEDIR} -I. 
LIBS= -lxml2 -lm -lpthread -lreadline
LIBXML=-L/usr/include/libxml2 
LIBS0=${LIBS} ${LIBXML} 

online_v2: main.o system.o shared_mem.o xml.o common.o user_info.o socket.o high_user.o queue.o
	gcc $(CFLAGS) $(LIBXMl) -o online_v2 main.o system.o shared_mem.o xml.o common.o user_info.o socket.o high_user.o queue.o $(LIBS)

   
main.o: main.c system.o shared_mem.o xml.o common.o user_info.o socket.o high_user.o queue.o
	gcc $(CFLAGS)  -c main.c 

system.o: system.c server.h
	gcc $(CFLAGS) -c system.c 

shared_mem.o: shared_mem.c server.h
	gcc $(CFLAGS) -c shared_mem.c 

xml.o: xml.c server.h
	gcc $(CFLAGS) -c xml.c 

common.o: common.c server.h
	gcc $(CFLAGS) -c common.c 

user_info.o: user_info.c server.h
	gcc $(CFLAGS) -c user_info.c 

socket.o: socket.c server.h
	gcc $(CFLAGS) -c socket.c   

high_user.o: high_user.c high_user.h
	gcc $(CFLAGS) -c high_user.c 

queue.o: queue.c queue.h
	gcc $(CFLAGS) -c queue.c                 
clean: 
	rm -f  *.o online_v2     
