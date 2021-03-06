#ifndef _QUEUE_H
#define _QUEUE_H

#include"server.h"
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define MAXQUE 256 

typedef struct
{
  int front, rear;
  int retrieve ;      
  int store ;         
  ANT_CMD command[MAXQUE]; // It indicates the Queue for Commands 
} Queue;

typedef struct
{
  int f, r;
  int ret ;      
  int s;         
  resp Resp[MAXQUE]; // It indicates the Queue for Commands 
} RQueue;


extern RQueue RQ ; 
RQueue RQ;

extern void rq_store(ANT_CMD );
extern resp *rq_retrieve(int );


extern Queue senQ,frontQ,backQ,fiberQ,selfQ,fpsQ,c1senQ,c1frontQ,c1fpsQ,c1backQ,c1fiberQ,c1selfQ,      			     c2senQ,c2frontQ,c2backQ,c2fpsQ,c2fiberQ,c2selfQ,c3senQ,c3frontQ,c3backQ,c3fpsQ,c3fiberQ,c3selfQ,
c4senQ,c4frontQ,c4fpsQ,c4backQ,c4fiberQ,c4selfQ,c5senQ,c5frontQ,c5backQ,c5fpsQ,c5fiberQ,c5selfQ,
c6senQ,c6frontQ,c6backQ,c6fpsQ,c6fiberQ,c6selfQ,c8senQ,c8frontQ,c8backQ,c8fiberQ,c8fpsQ,c8selfQ,
c9senQ,c9frontQ,c9backQ,c9fiberQ,c9fpsQ,c9selfQ,c10senQ,c10frontQ,c10backQ,c10fiberQ,c10fpsQ,c10selfQ,
c11senQ,c11frontQ,c11backQ,c11fiberQ,c11fpsQ,c11selfQ,c12senQ,c12frontQ,c12backQ,c12fiberQ,c12fpsQ,c12selfQ
,c13senQ,c13frontQ,c13backQ,c13fiberQ,c13fpsQ,c13selfQ,c14senQ,c14frontQ,c14backQ,c14fiberQ,c14fpsQ,c14selfQ,
e2senQ,e2frontQ,e2backQ,e2fpsQ,e2fiberQ,e2selfQ,e3senQ,e3frontQ,e3backQ,e3fpsQ,e3fiberQ,e3selfQ
,e4senQ,e4frontQ,e4backQ,e4fpsQ,e4fiberQ,e4selfQ,e5senQ,e5frontQ,e5backQ,e5fpsQ,e5fiberQ,e5selfQ
,e6senQ,e6frontQ,e6backQ,e6fpsQ,e6fiberQ,e6selfQ,s2senQ,s2frontQ,s2backQ,s2fpsQ,s2fiberQ,s2selfQ,
s3senQ,s3frontQ,s3backQ,s3fpsQ,s3fiberQ,s3selfQ,s4senQ,s4frontQ,s4backQ,s4fpsQ,s4fiberQ,s4selfQ,
s1senQ,s1frontQ,s1backQ,s1fpsQ,s1fiberQ,s1selfQ,s6senQ,s6frontQ,s6backQ,s6fpsQ,s6fiberQ,s6selfQ,
w1senQ,w1frontQ,w1backQ,w1fpsQ,w1fiberQ,w1selfQ,w2senQ,w2frontQ,w2backQ,w2fpsQ,w2fiberQ,w2selfQ,
w3senQ,w3frontQ,w3backQ,w3fpsQ,w3fiberQ,w3selfQ,w4senQ,w4frontQ,w4backQ,w4fpsQ,w4fiberQ,w4selfQ,
w5senQ,w5frontQ,w5backQ,w5fpsQ,w5fiberQ,w5selfQ,w6senQ,w6frontQ,w6backQ,w6fpsQ,w6fiberQ,w6selfQ;

 
Queue senQ,frontQ,backQ,fiberQ,selfQ,fpsQ,c1senQ,c1frontQ,c1fpsQ,c1backQ,c1fiberQ,c1selfQ,     			      c2senQ,c2frontQ,c2backQ,c2fpsQ,c2fiberQ,c2selfQ,c3senQ,c3frontQ,c3backQ,c3fpsQ,c3fiberQ,c3selfQ,
c4senQ,c4frontQ,c4fpsQ,c4backQ,c4fiberQ,c4selfQ,c5senQ,c5frontQ,c5backQ,c5fpsQ,c5fiberQ,c5selfQ,
c6senQ,c6frontQ,c6backQ,c6fpsQ,c6fiberQ,c6selfQ,c8senQ,c8frontQ,c8backQ,c8fiberQ,c8fpsQ,c8selfQ,
c9senQ,c9frontQ,c9backQ,c9fiberQ,c9fpsQ,c9selfQ,c10senQ,c10frontQ,c10backQ,c10fiberQ,c10fpsQ,c10selfQ,
c11senQ,c11frontQ,c11backQ,c11fiberQ,c11fpsQ,c11selfQ,c12senQ,c12frontQ,c12backQ,c12fiberQ,c12fpsQ,c12selfQ
,c13senQ,c13frontQ,c13backQ,c13fiberQ,c13fpsQ,c13selfQ,c14senQ,c14frontQ,c14backQ,c14fiberQ,c14fpsQ,c14selfQ,
e2senQ,e2frontQ,e2backQ,e2fpsQ,e2fiberQ,e2selfQ,e3senQ,e3frontQ,e3backQ,e3fpsQ,e3fiberQ,e3selfQ
,e4senQ,e4frontQ,e4backQ,e4fpsQ,e4fiberQ,e4selfQ,e5senQ,e5frontQ,e5backQ,e5fpsQ,e5fiberQ,e5selfQ
,e6senQ,e6frontQ,e6backQ,e6fpsQ,e6fiberQ,e6selfQ,s2senQ,s2frontQ,s2backQ,s2fpsQ,s2fiberQ,s2selfQ,
s3senQ,s3frontQ,s3backQ,s3fpsQ,s3fiberQ,s3selfQ,s4senQ,s4frontQ,s4backQ,s4fpsQ,s4fiberQ,s4selfQ,
s1senQ,s1frontQ,s1backQ,s1fpsQ,s1fiberQ,s1selfQ,s6senQ,s6frontQ,s6backQ,s6fpsQ,s6fiberQ,s6selfQ,
w1senQ,w1frontQ,w1backQ,w1fpsQ,w1fiberQ,w1selfQ,w2senQ,w2frontQ,w2backQ,w2fpsQ,w2fiberQ,w2selfQ,
w3senQ,w3frontQ,w3backQ,w3fpsQ,w3fiberQ,w3selfQ,w4senQ,w4frontQ,w4backQ,w4fpsQ,w4fiberQ,w4selfQ,
w5senQ,w5frontQ,w5backQ,w5fpsQ,w5fiberQ,w5selfQ,w6senQ,w6frontQ,w6backQ,w6fpsQ,w6fiberQ,w6selfQ;


/* C00 Antenna System Queues */

extern void senq_store(ANT_CMD );
extern ANT_CMD *senq_retrieve(int );

extern void frontq_store(ANT_CMD );
extern ANT_CMD *frontq_retrieve(int );

extern void fiberq_store(ANT_CMD );
extern ANT_CMD *fiberq_retrieve(int );

extern void backq_store(ANT_CMD );
extern ANT_CMD *backq_retrieve(int );

extern void selfq_store(ANT_CMD );
extern ANT_CMD *selfq_retrieve(int );

extern void fpsq_store(ANT_CMD );
extern ANT_CMD *fpsq_retrieve(int );

/**** C01 Antenna system Queue */

extern void c1_senq_store(ANT_CMD );
extern ANT_CMD *c1_senq_retrieve(int );

extern void c1_frontq_store(ANT_CMD );
extern ANT_CMD *c1_frontq_retrieve(int );

extern void c1_fiberq_store(ANT_CMD );
extern ANT_CMD *c1_fiberq_retrieve(int );

extern void c1_backq_store(ANT_CMD );
extern ANT_CMD *c1_backq_retrieve(int );

extern void c1_selfq_store(ANT_CMD );
extern ANT_CMD *c1_selfq_retrieve(int );

extern void c1_fpsq_store(ANT_CMD );
extern ANT_CMD *c1_fpsq_retrieve(int );

/**** C02 Antenna system Queue */

extern void c2_senq_store(ANT_CMD );
extern ANT_CMD *c2_senq_retrieve(int );

extern void c2_frontq_store(ANT_CMD );
extern ANT_CMD *c2_frontq_retrieve(int );

extern void c2_fiberq_store(ANT_CMD );
extern ANT_CMD *c2_fiberq_retrieve(int );

extern void c2_backq_store(ANT_CMD );
extern ANT_CMD *c2_backq_retrieve(int );

extern void c2_selfq_store(ANT_CMD );
extern ANT_CMD *c2_selfq_retrieve(int );

extern void c2_fpsq_store(ANT_CMD );
extern ANT_CMD *c2_fpsq_retrieve(int );

/**** C03 Antenna system Queue */

extern void c3_senq_store(ANT_CMD );
extern ANT_CMD *c3_senq_retrieve(int );

extern void c3_frontq_store(ANT_CMD );
extern ANT_CMD *c3_frontq_retrieve(int );

extern void c3_fiberq_store(ANT_CMD );
extern ANT_CMD *c3_fiberq_retrieve(int );

extern void c3_backq_store(ANT_CMD );
extern ANT_CMD *c3_backq_retrieve(int );

extern void c3_selfq_store(ANT_CMD );
extern ANT_CMD *c3_selfq_retrieve(int );

extern void c3_fpsq_store(ANT_CMD );
extern ANT_CMD *c3_fpsq_retrieve(int );

/**** C04 Antenna system Queue */

extern void c4_senq_store(ANT_CMD );
extern ANT_CMD *c4_senq_retrieve(int );

extern void c4_frontq_store(ANT_CMD );
extern ANT_CMD *c4_frontq_retrieve(int );

extern void c4_fiberq_store(ANT_CMD );
extern ANT_CMD *c4_fiberq_retrieve(int );

extern void c4_backq_store(ANT_CMD );
extern ANT_CMD *c4_backq_retrieve(int );

extern void c4_selfq_store(ANT_CMD );
extern ANT_CMD *c4_selfq_retrieve(int );

extern void c4_fpsq_store(ANT_CMD );
extern ANT_CMD *c4_fpsq_retrieve(int );

/**** C05 Antenna system Queue */

extern void c5_senq_store(ANT_CMD );
extern ANT_CMD *c5_senq_retrieve(int );

extern void c5_frontq_store(ANT_CMD );
extern ANT_CMD *c5_frontq_retrieve(int );

extern void c5_fiberq_store(ANT_CMD );
extern ANT_CMD *c5_fiberq_retrieve(int );

extern void c5_backq_store(ANT_CMD );
extern ANT_CMD *c5_backq_retrieve(int );

extern void c5_selfq_store(ANT_CMD );
extern ANT_CMD *c5_selfq_retrieve(int );

extern void c5_fpsq_store(ANT_CMD );
extern ANT_CMD *c5_fpsq_retrieve(int );

/**** C06 Antenna system Queue */

extern void c6_senq_store(ANT_CMD );
extern ANT_CMD *c6_senq_retrieve(int );

extern void c6_frontq_store(ANT_CMD );
extern ANT_CMD *c6_frontq_retrieve(int );

extern void c6_fiberq_store(ANT_CMD );
extern ANT_CMD *c6_fiberq_retrieve(int );

extern void c6_backq_store(ANT_CMD );
extern ANT_CMD *c6_backq_retrieve(int );

extern void c6_selfq_store(ANT_CMD );
extern ANT_CMD *c6_selfq_retrieve(int );

extern void c6_fpsq_store(ANT_CMD );
extern ANT_CMD *c6_fpsq_retrieve(int );

/**** C08 Antenna system Queue */

extern void c8_senq_store(ANT_CMD );
extern ANT_CMD *c8_senq_retrieve(int );

extern void c8_frontq_store(ANT_CMD );
extern ANT_CMD *c8_frontq_retrieve(int );

extern void c8_fiberq_store(ANT_CMD );
extern ANT_CMD *c8_fiberq_retrieve(int );

extern void c8_backq_store(ANT_CMD );
extern ANT_CMD *c8_backq_retrieve(int );

extern void c8_selfq_store(ANT_CMD );
extern ANT_CMD *c8_selfq_retrieve(int );

extern void c8_fpsq_store(ANT_CMD );
extern ANT_CMD *c8_fpsq_retrieve(int );

/**** C09 Antenna system Queue */

extern void c9_senq_store(ANT_CMD );
extern ANT_CMD *c9_senq_retrieve(int );

extern void c9_frontq_store(ANT_CMD );
extern ANT_CMD *c9_frontq_retrieve(int );

extern void c9_fiberq_store(ANT_CMD );
extern ANT_CMD *c9_fiberq_retrieve(int );

extern void c9_backq_store(ANT_CMD );
extern ANT_CMD *c9_backq_retrieve(int );

extern void c9_selfq_store(ANT_CMD );
extern ANT_CMD *c9_selfq_retrieve(int );

extern void c9_fpsq_store(ANT_CMD );
extern ANT_CMD *c9_fpsq_retrieve(int );

/**** C10 Antenna system Queue */

extern void c10_senq_store(ANT_CMD );
extern ANT_CMD *c10_senq_retrieve(int );

extern void c10_frontq_store(ANT_CMD );
extern ANT_CMD *c10_frontq_retrieve(int );

extern void c10_fiberq_store(ANT_CMD );
extern ANT_CMD *c10_fiberq_retrieve(int );

extern void c10_backq_store(ANT_CMD );
extern ANT_CMD *c10_backq_retrieve(int );

extern void c10_selfq_store(ANT_CMD );
extern ANT_CMD *c10_selfq_retrieve(int );

extern void c10_fpsq_store(ANT_CMD );
extern ANT_CMD *c10_fpsq_retrieve(int );

/**** C11 Antenna system Queue */

extern void c11_senq_store(ANT_CMD );
extern ANT_CMD *c11_senq_retrieve(int );

extern void c11_frontq_store(ANT_CMD );
extern ANT_CMD *c11_frontq_retrieve(int );

extern void c11_fiberq_store(ANT_CMD );
extern ANT_CMD *c11_fiberq_retrieve(int );

extern void c11_backq_store(ANT_CMD );
extern ANT_CMD *c11_backq_retrieve(int );

extern void c11_selfq_store(ANT_CMD );
extern ANT_CMD *c11_selfq_retrieve(int );

extern void c11_fpsq_store(ANT_CMD );
extern ANT_CMD *c11_fpsq_retrieve(int );

/**** C12 Antenna system Queue */

extern void c12_senq_store(ANT_CMD );
extern ANT_CMD *c12_senq_retrieve(int );

extern void c12_frontq_store(ANT_CMD );
extern ANT_CMD *c12_frontq_retrieve(int );

extern void c12_fiberq_store(ANT_CMD );
extern ANT_CMD *c12_fiberq_retrieve(int );

extern void c12_backq_store(ANT_CMD );
extern ANT_CMD *c12_backq_retrieve(int );

extern void c12_selfq_store(ANT_CMD );
extern ANT_CMD *c12_selfq_retrieve(int );

extern void c12_fpsq_store(ANT_CMD );
extern ANT_CMD *c12_fpsq_retrieve(int );


/**** C13 Antenna system Queue */

extern void c13_senq_store(ANT_CMD );
extern ANT_CMD *c13_senq_retrieve(int );

extern void c13_frontq_store(ANT_CMD );
extern ANT_CMD *c13_frontq_retrieve(int );

extern void c13_fiberq_store(ANT_CMD );
extern ANT_CMD *c13_fiberq_retrieve(int );

extern void c13_backq_store(ANT_CMD );
extern ANT_CMD *c13_backq_retrieve(int );

extern void c13_selfq_store(ANT_CMD );
extern ANT_CMD *c13_selfq_retrieve(int );

extern void c13_fpsq_store(ANT_CMD );
extern ANT_CMD *c13_fpsq_retrieve(int );

/**** c14 Antenna system Queue */

extern void c14_senq_store(ANT_CMD );
extern ANT_CMD *c14_senq_retrieve(int );

extern void c14_frontq_store(ANT_CMD );
extern ANT_CMD *c14_frontq_retrieve(int );

extern void c14_fiberq_store(ANT_CMD );
extern ANT_CMD *c14_fiberq_retrieve(int );

extern void c14_backq_store(ANT_CMD );
extern ANT_CMD *c14_backq_retrieve(int );

extern void c14_selfq_store(ANT_CMD );
extern ANT_CMD *c14_selfq_retrieve(int );

extern void c14_fpsq_store(ANT_CMD );
extern ANT_CMD *c14_fpsq_retrieve(int );

/**** E02 Antenna system Queue */

extern void e2_senq_store(ANT_CMD );
extern ANT_CMD *e2_senq_retrieve(int );

extern void e2_frontq_store(ANT_CMD );
extern ANT_CMD *e2_frontq_retrieve(int );

extern void e2_fiberq_store(ANT_CMD );
extern ANT_CMD *e2_fiberq_retrieve(int );

extern void e2_backq_store(ANT_CMD );
extern ANT_CMD *e2_backq_retrieve(int );

extern void e2_selfq_store(ANT_CMD );
extern ANT_CMD *e2_selfq_retrieve(int );

extern void e2_fpsq_store(ANT_CMD );
extern ANT_CMD *e2_fpsq_retrieve(int );

/**** E03 Antenna system Queue */

extern void e3_senq_store(ANT_CMD );
extern ANT_CMD *e3_senq_retrieve(int );

extern void e3_frontq_store(ANT_CMD );
extern ANT_CMD *e3_frontq_retrieve(int );

extern void e3_fiberq_store(ANT_CMD );
extern ANT_CMD *e3_fiberq_retrieve(int );

extern void e3_backq_store(ANT_CMD );
extern ANT_CMD *e3_backq_retrieve(int );

extern void e3_selfq_store(ANT_CMD );
extern ANT_CMD *e3_selfq_retrieve(int );

extern void e3_fpsq_store(ANT_CMD );
extern ANT_CMD *e3_fpsq_retrieve(int );


/**** E04 Antenna system Queue */

extern void e4_senq_store(ANT_CMD );
extern ANT_CMD *e4_senq_retrieve(int );

extern void e4_frontq_store(ANT_CMD );
extern ANT_CMD *e4_frontq_retrieve(int );

extern void e4_fiberq_store(ANT_CMD );
extern ANT_CMD *e4_fiberq_retrieve(int );

extern void e4_backq_store(ANT_CMD );
extern ANT_CMD *e4_backq_retrieve(int );

extern void e4_selfq_store(ANT_CMD );
extern ANT_CMD *e4_selfq_retrieve(int );

extern void e4_fpsq_store(ANT_CMD );
extern ANT_CMD *e4_fpsq_retrieve(int );

/**** E05 Antenna system Queue */

extern void e5_senq_store(ANT_CMD );
extern ANT_CMD *e5_senq_retrieve(int );

extern void e5_frontq_store(ANT_CMD );
extern ANT_CMD *e5_frontq_retrieve(int );

extern void e5_fiberq_store(ANT_CMD );
extern ANT_CMD *e5_fiberq_retrieve(int );

extern void e5_backq_store(ANT_CMD );
extern ANT_CMD *e5_backq_retrieve(int );

extern void e5_selfq_store(ANT_CMD );
extern ANT_CMD *e5_selfq_retrieve(int );

extern void e5_fpsq_store(ANT_CMD );
extern ANT_CMD *e5_fpsq_retrieve(int );

/**** E06 Antenna system Queue */

extern void e6_senq_store(ANT_CMD );
extern ANT_CMD *e6_senq_retrieve(int );

extern void e6_frontq_store(ANT_CMD );
extern ANT_CMD *e6_frontq_retrieve(int );

extern void e6_fiberq_store(ANT_CMD );
extern ANT_CMD *e6_fiberq_retrieve(int );

extern void e6_backq_store(ANT_CMD );
extern ANT_CMD *e6_backq_retrieve(int );

extern void e6_selfq_store(ANT_CMD );
extern ANT_CMD *e6_selfq_retrieve(int );

extern void e6_fpsq_store(ANT_CMD );
extern ANT_CMD *e6_fpsq_retrieve(int );

/**** S01 Antenna system Queue */

extern void s1_senq_store(ANT_CMD );
extern ANT_CMD *s1_senq_retrieve(int );

extern void s1_frontq_store(ANT_CMD );
extern ANT_CMD *s1_frontq_retrieve(int );

extern void s1_fiberq_store(ANT_CMD );
extern ANT_CMD *s1_fiberq_retrieve(int );

extern void s1_backq_store(ANT_CMD );
extern ANT_CMD *s1_backq_retrieve(int );

extern void s1_selfq_store(ANT_CMD );
extern ANT_CMD *s1_selfq_retrieve(int );

extern void s1_fpsq_store(ANT_CMD );
extern ANT_CMD *s1_fpsq_retrieve(int );

/**** S02 Antenna system Queue */

extern void s2_senq_store(ANT_CMD );
extern ANT_CMD *s2_senq_retrieve(int );

extern void s2_frontq_store(ANT_CMD );
extern ANT_CMD *s2_frontq_retrieve(int );

extern void s2_fiberq_store(ANT_CMD );
extern ANT_CMD *s2_fiberq_retrieve(int );

extern void s2_backq_store(ANT_CMD );
extern ANT_CMD *s2_backq_retrieve(int );

extern void s2_selfq_store(ANT_CMD );
extern ANT_CMD *s2_selfq_retrieve(int );

extern void s2_fpsq_store(ANT_CMD );
extern ANT_CMD *s2_fpsq_retrieve(int );

/**** S03 Antenna system Queue */

extern void s3_senq_store(ANT_CMD );
extern ANT_CMD *s3_senq_retrieve(int );

extern void s3_frontq_store(ANT_CMD );
extern ANT_CMD *s3_frontq_retrieve(int );

extern void s3_fiberq_store(ANT_CMD );
extern ANT_CMD *s3_fiberq_retrieve(int );

extern void s3_backq_store(ANT_CMD );
extern ANT_CMD *s3_backq_retrieve(int );

extern void s3_selfq_store(ANT_CMD );
extern ANT_CMD *s3_selfq_retrieve(int );

extern void s3_fpsq_store(ANT_CMD );
extern ANT_CMD *s3_fpsq_retrieve(int );

/**** S04 Antenna system Queue */

extern void s4_senq_store(ANT_CMD );
extern ANT_CMD *s4_senq_retrieve(int );

extern void s4_frontq_store(ANT_CMD );
extern ANT_CMD *s4_frontq_retrieve(int );

extern void s4_fiberq_store(ANT_CMD );
extern ANT_CMD *s4_fiberq_retrieve(int );

extern void s4_backq_store(ANT_CMD );
extern ANT_CMD *s4_backq_retrieve(int );

extern void s4_selfq_store(ANT_CMD );
extern ANT_CMD *s4_selfq_retrieve(int );

extern void s4_fpsq_store(ANT_CMD );
extern ANT_CMD *s4_fpsq_retrieve(int );

/**** S06 Antenna system Queue */

extern void s6_senq_store(ANT_CMD );
extern ANT_CMD *s6_senq_retrieve(int );

extern void s6_frontq_store(ANT_CMD );
extern ANT_CMD *s6_frontq_retrieve(int );

extern void s6_fiberq_store(ANT_CMD );
extern ANT_CMD *s6_fiberq_retrieve(int );

extern void s6_backq_store(ANT_CMD );
extern ANT_CMD *s6_backq_retrieve(int );

extern void s6_selfq_store(ANT_CMD );
extern ANT_CMD *s6_selfq_retrieve(int );

extern void s6_fpsq_store(ANT_CMD );
extern ANT_CMD *s6_fpsq_retrieve(int );

/**** W01 Antenna system Queue */

extern void w1_senq_store(ANT_CMD );
extern ANT_CMD *w1_senq_retrieve(int );

extern void w1_frontq_store(ANT_CMD );
extern ANT_CMD *w1_frontq_retrieve(int );

extern void w1_fiberq_store(ANT_CMD );
extern ANT_CMD *w1_fiberq_retrieve(int );

extern void w1_backq_store(ANT_CMD );
extern ANT_CMD *w1_backq_retrieve(int );

extern void w1_selfq_store(ANT_CMD );
extern ANT_CMD *w1_selfq_retrieve(int );

extern void w1_fpsq_store(ANT_CMD );
extern ANT_CMD *w1_fpsq_retrieve(int );

/**** W02 Antenna system Queue */

extern void w2_senq_store(ANT_CMD );
extern ANT_CMD *w2_senq_retrieve(int );

extern void w2_frontq_store(ANT_CMD );
extern ANT_CMD *w2_frontq_retrieve(int );

extern void w2_fiberq_store(ANT_CMD );
extern ANT_CMD *w2_fiberq_retrieve(int );

extern void w2_backq_store(ANT_CMD );
extern ANT_CMD *w2_backq_retrieve(int );

extern void w2_selfq_store(ANT_CMD );
extern ANT_CMD *w2_selfq_retrieve(int );

extern void w2_fpsq_store(ANT_CMD );
extern ANT_CMD *w2_fpsq_retrieve(int );

/**** W03 Antenna system Queue */

extern void w3_senq_store(ANT_CMD );
extern ANT_CMD *w3_senq_retrieve(int );

extern void w3_frontq_store(ANT_CMD );
extern ANT_CMD *w3_frontq_retrieve(int );

extern void w3_fiberq_store(ANT_CMD );
extern ANT_CMD *w3_fiberq_retrieve(int );

extern void w3_backq_store(ANT_CMD );
extern ANT_CMD *w3_backq_retrieve(int );

extern void w3_selfq_store(ANT_CMD );
extern ANT_CMD *w3_selfq_retrieve(int );

extern void w3_fpsq_store(ANT_CMD );
extern ANT_CMD *w3_fpsq_retrieve(int );

/**** W04 Antenna system Queue */

extern void w4_senq_store(ANT_CMD );
extern ANT_CMD *w4_senq_retrieve(int );

extern void w4_frontq_store(ANT_CMD );
extern ANT_CMD *w4_frontq_retrieve(int );

extern void w4_fiberq_store(ANT_CMD );
extern ANT_CMD *w4_fiberq_retrieve(int );

extern void w4_backq_store(ANT_CMD );
extern ANT_CMD *w4_backq_retrieve(int );

extern void w4_selfq_store(ANT_CMD );
extern ANT_CMD *w4_selfq_retrieve(int );

extern void w4_fpsq_store(ANT_CMD );
extern ANT_CMD *w4_fpsq_retrieve(int );

/**** W06 Antenna system Queue */

extern void w6_senq_store(ANT_CMD );
extern ANT_CMD *w6_senq_retrieve(int );

extern void w6_frontq_store(ANT_CMD );
extern ANT_CMD *w6_frontq_retrieve(int );

extern void w6_fiberq_store(ANT_CMD );
extern ANT_CMD *w6_fiberq_retrieve(int );

extern void w6_backq_store(ANT_CMD );
extern ANT_CMD *w6_backq_retrieve(int );

extern void w6_selfq_store(ANT_CMD );
extern ANT_CMD *w6_selfq_retrieve(int );

extern void w6_fpsq_store(ANT_CMD );
extern ANT_CMD *w6_fpsq_retrieve(int );

/**** W05 Antenna system Queue */

extern void w5_senq_store(ANT_CMD );
extern ANT_CMD *w5_senq_retrieve(int );

extern void w5_frontq_store(ANT_CMD );
extern ANT_CMD *w5_frontq_retrieve(int );

extern void w5_fiberq_store(ANT_CMD );
extern ANT_CMD *w5_fiberq_retrieve(int );

extern void w5_backq_store(ANT_CMD );
extern ANT_CMD *w5_backq_retrieve(int );

extern void w5_selfq_store(ANT_CMD );
extern ANT_CMD *w5_selfq_retrieve(int );

extern void w5_fpsq_store(ANT_CMD );
extern ANT_CMD *w5_fpsq_retrieve(int );




#endif
