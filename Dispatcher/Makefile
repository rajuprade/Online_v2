INCLUDEDIR	=-I /usr/include/libxml2 
CFLAGS          = -Wall -g 
LIBS= -lpthread
#LIBXML=-L/usr/include/libxml2 
#LIBS0=${LIBS} ${LIBXML} 

abc: abc.o socket.o queue.o antenna_thread.o mcm_thread.o
	gcc $(CFLAGS) -o abc abc.o socket.o queue.o antenna_thread.o mcm_thread.o $(LIBS)
 
abc.o: abc.c socket.o
	gcc $(CFLAGS)  -c abc.c 

socket.o: socket.c server.h
	gcc $(CFLAGS) -c socket.c  

queue.o:  queue.c queue.h 
	gcc $(CFLAGS) -c queue.c

antenna_thread.o:  antenna_thread.c ant_thread.h 
	gcc $(CFLAGS) -c antenna_thread.c 

mcm_thread.o:  mcm_thread.c mcm_thread.h 
	gcc $(CFLAGS) -c mcm_thread.c                
clean: 
	rm -f  *.o abc     
