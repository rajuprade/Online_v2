#ifndef _SERVOQUEUE_H
#define _SERVOQUEUE_H

#include"servo.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"servo.h"
#define MAXQUE 256 

typedef struct
{
  int front, rear;
  int retrieve ;      
  int store ;         
  SRVANT_CMD srvcmd[MAXQUE]; // It indicates the Queue for Commands 
} SQueue;

typedef struct
{
  int f, r;
  int ret ;      
  int s;         
  servoresp srvresp[MAXQUE]; // It indicates the Queue for Commands 
} SRQueue;


extern SQueue C00srvq,C01srvq,C02srvq,C03srvq,C04srvq,C05srvq,C06srvq,C08srvq,C09srvq,C10srvq,
       C11srvq,C12srvq,C13srvq,C14srvq,E02srvq,E03srvq,E04srvq,E05srvq,E06srvq,S01srvq,S02srvq
       ,S03srvq,S04srvq,S06srvq,W01srvq,W02srvq,W03srvq,W04srvq,W05srvq,W06srvq  ;

SQueue C00srvq,C01srvq,C02srvq,C03srvq,C04srvq,C05srvq,C06srvq,C08srvq,C09srvq,C10srvq,
       C11srvq,C12srvq,C13srvq,C14srvq,E02srvq,E03srvq,E04srvq,E05srvq,E06srvq,S01srvq,S02srvq
       ,S03srvq,S04srvq,S06srvq,W01srvq,W02srvq,W03srvq,W04srvq,W05srvq,W06srvq ;

/* C00 Antenna SERVO System Queues */

extern void C00srv_store(SRVANT_CMD );
extern SRVANT_CMD *C00srv_retrieve(int );

/* C01 Antenna Servo system queues */

extern void C01srv_store(SRVANT_CMD );
extern SRVANT_CMD *C01srv_retrieve(int );

/* C02 Antenna Servo system queues */

extern void C02srv_store(SRVANT_CMD );
extern SRVANT_CMD *C02srv_retrieve(int );

/* C03 Antenna Servo system queues */

extern void C03srv_store(SRVANT_CMD );
extern SRVANT_CMD *C03srv_retrieve(int );

/* C04 Antenna Servo system queues */

extern void C04srv_store(SRVANT_CMD );
extern SRVANT_CMD *C04srv_retrieve(int );

/* C05 Antenna Servo system queues */

extern void C05srv_store(SRVANT_CMD );
extern SRVANT_CMD *C05srv_retrieve(int );

/* C06 Antenna Servo system queues */

extern void C06srv_store(SRVANT_CMD );
extern SRVANT_CMD *C06srv_retrieve(int );

/* C08 Antenna Servo system queues */

extern void C08srv_store(SRVANT_CMD );
extern SRVANT_CMD *C08srv_retrieve(int );

/* C09 Antenna Servo system queues */

extern void C09srv_store(SRVANT_CMD );
extern SRVANT_CMD *C09srv_retrieve(int );

/* C10 Antenna Servo system queues */

extern void C10srv_store(SRVANT_CMD );
extern SRVANT_CMD *C10srv_retrieve(int );

/* C11 Antenna Servo system queues */

extern void C11srv_store(SRVANT_CMD );
extern SRVANT_CMD *C11srv_retrieve(int );

/* C12 Antenna Servo system queues */

extern void C12srv_store(SRVANT_CMD );
extern SRVANT_CMD *C12srv_retrieve(int );

/* C13 Antenna Servo system queues */

extern void C13srv_store(SRVANT_CMD );
extern SRVANT_CMD *C13srv_retrieve(int );

/* C14 Antenna Servo system queues */

extern void C14srv_store(SRVANT_CMD );
extern SRVANT_CMD *C14srv_retrieve(int );

/* E02 Antenna Servo system queues */

extern void E02srv_store(SRVANT_CMD );
extern SRVANT_CMD *E02srv_retrieve(int );

/* E03 Antenna Servo system queues */

extern void E03srv_store(SRVANT_CMD );
extern SRVANT_CMD *E03srv_retrieve(int );

/* E04 Antenna Servo system queues */

extern void E04srv_store(SRVANT_CMD );
extern SRVANT_CMD *E04srv_retrieve(int );

/* E05 Antenna Servo system queues */

extern void E05srv_store(SRVANT_CMD );
extern SRVANT_CMD *E05srv_retrieve(int );

/* E06 Antenna Servo system queues */

extern void E06srv_store(SRVANT_CMD );
extern SRVANT_CMD *E06srv_retrieve(int );

/* S01 Antenna Servo system queues */

extern void S01srv_store(SRVANT_CMD );
extern SRVANT_CMD *S01srv_retrieve(int );

/* S02 Antenna Servo system queues */

extern void S02srv_store(SRVANT_CMD );
extern SRVANT_CMD *S02srv_retrieve(int );

/* S03 Antenna Servo system queues */

extern void S03srv_store(SRVANT_CMD );
extern SRVANT_CMD *S03srv_retrieve(int );

/* S04 Antenna Servo system queues */

extern void S04srv_store(SRVANT_CMD );
extern SRVANT_CMD *S04srv_retrieve(int );

/* S06 Antenna Servo system queues */

extern void S06srv_store(SRVANT_CMD );
extern SRVANT_CMD *S06srv_retrieve(int );

/* W01 Antenna Servo system queues */

extern void W01srv_store(SRVANT_CMD );
extern SRVANT_CMD *W01srv_retrieve(int );


/* W02 Antenna Servo system queues */

extern void W02srv_store(SRVANT_CMD );
extern SRVANT_CMD *W02srv_retrieve(int );

/* W03 Antenna Servo system queues */

extern void W03srv_store(SRVANT_CMD );
extern SRVANT_CMD *W03srv_retrieve(int );

/* W04 Antenna Servo system queues */

extern void W04srv_store(SRVANT_CMD );
extern SRVANT_CMD *W04srv_retrieve(int );

/* W05 Antenna Servo system queues */

extern void W05srv_store(SRVANT_CMD );
extern SRVANT_CMD *W05srv_retrieve(int );

/* W06 Antenna Servo system queues */

extern void W06srv_store(SRVANT_CMD );
extern SRVANT_CMD *W06srv_retrieve(int );
#endif
