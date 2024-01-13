#pragma once
#include "./bits.h"
#include <stdlib.h>

typedef struct Queue{
    void *data;unsigned long size;int hh,tt;
}queue;

queue *creat_queue(unsigned long size,unsigned long total_elem){
    queue* res=malloc(sizeof(queue));
    res->data=malloc(size*total_elem);
    res->size=size,res->hh=res->tt=0;
    return res;
}

void pophead(queue* q,void *recv){
    if (q->hh<q->tt) copy(recv,q->data+(q->size)*(q->hh),q->size),q->hh++;
}

void push(queue* q,void *elem){
    copy(q->data+(q->size)*((q->tt)++),elem,q->size);
}

void freeq(queue* q){
    free(q->data),free(q);
}