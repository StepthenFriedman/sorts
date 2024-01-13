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

void freetree(node *top){
    if (top->ls!=NULL) freetree(top->ls);
    if (top->rs!=NULL) freetree(top->rs);
    free(top->value);
    free(top);
}

void printqueue(queue* q){
    for (int i=q->hh;i<q->tt;i++) printf("%d ",*(int*)(((node*)(q->data+(q->size)*i))->value));
    putchar('\n');
}

void sortq(queue* q,int (*cmpnode)(const void *,const void *)){
    isort(q->data+(q->size)*(q->hh),(unsigned long)(q->tt-q->hh),q->size,cmpnode);
}


void ctsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    int cmpnode(const void *a,const void *b){
        return cmp(((node*)a)->value,((node*)b)->value);
    }
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
    push(pq,*stack);
    while (sortedNum<total_elem){
        pophead(pq,elem);
        copy(start+size*sortedNum,elem->value,size);
        if (elem->ls!=NULL) push(pq,elem->ls);
        if (elem->rs!=NULL) push(pq,elem->rs);
        sortq(pq,cmpnode);
        sortedNum++;
    }
    freetree(*stack);
    free(stack),free(elem),freeq(pq);
}