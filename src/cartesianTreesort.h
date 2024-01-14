#pragma once
#include "./bits.h"
#include "./priority_queue.h"
#include "./insertionsort.h"
#include <stdlib.h>

typedef struct Node{
    void *value;struct Node *ls,*rs;
}node;

node *creat_node(void *ptr,unsigned long size){
    node* res=malloc(sizeof(node));
    res->value=malloc(size);
    copy(res->value,ptr,size);
    res->ls=res->rs=NULL;
    return res;
}

void sortq(queue* q,int (*cmpnode)(const void *,const void *)){
    insertonce(q->data+(q->size)*(q->hh),(unsigned long)(q->tt-q->hh),q->size,cmpnode);
}

void freeq(queue* q){
    free(q->data),free(q);
}

void ctsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    int cmpnode(const void *a,const void *b){return cmp(((node*)a)->value,((node*)b)->value);}
    node **stack=malloc(total_elem*sizeof(node*)), *newelem,
    **top=stack,**k;
    for (void *ptr=start;ptr<start+total_elem*size;ptr+=size) {
        k=top;
        while (k>stack && cmp((*(k-1))->value,ptr)>0) k--;
        newelem=creat_node(ptr,size);
        if (k>stack) (*(k-1))->rs=newelem;
        if (k<top) newelem->ls=*k;
        *(k++)=newelem;
        top=k;
    }
    node *elem=(node*)malloc(sizeof(node));
    int sortedNum=0;
    queue* pq=creat_queue(sizeof(node),total_elem);
    pushback(pq,*stack);
    free(*stack),free(stack);
    while (sortedNum<total_elem){
        pophead(pq,elem);
        copy(start+size*sortedNum,elem->value,size);
        free(elem->value);
        if (elem->ls!=NULL) pushback(pq,elem->ls),free(elem->ls),sortq(pq,cmpnode);
        if (elem->rs!=NULL) pushback(pq,elem->rs),free(elem->rs),sortq(pq,cmpnode);
        sortedNum++;
    }
    free(elem),freeq(pq);
}