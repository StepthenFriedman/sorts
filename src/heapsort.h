#pragma once
#include "./bits.h"

void heapify_2branch(void *start,unsigned long father,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    start-=size;
    unsigned long this,next;
    for (this=father,next=this*2;next<=total_elem;this=next,next*=2){
        if (next+1<=total_elem && cmp(start+size*next,start+size*(next+1))<0) next++;
        if (cmp(start+size*this,start+size*next)<0) swap(start+size*this,start+size*next,size);
        else break;
    }
}

void hsort_2branch(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start+(total_elem-1)*size;
    unsigned long ptr;
    for (ptr=(total_elem)/2;ptr>0;ptr--) heapify_2branch(start,ptr,total_elem,size,cmp);
    for (;sorted>start;sorted-=size){
        swap(sorted,start,size);
        heapify_2branch(start,1,--total_elem,size,cmp);
    }
}

void heapify_4branch(void *start,unsigned long father,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    start-=size;
    long this,next,max,i;
    for (this=father,next=this*4;next-2<=total_elem;this=next,next*=4){
        max=next-2;
        for (i=-2;i<2;i++) {
            if (next+i>total_elem) break;
            else if (cmp(start+size*max,start+size*(next+i))<0) max=next+i;
        }
        next=max;
        if (cmp(start+size*this,start+size*next)<0) swap(start+size*this,start+size*next,size);
        else break;
    }
}

void hsort_4branch(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start+(total_elem-1)*size;
    unsigned long ptr;
    for (ptr=(total_elem)/4;ptr>0;ptr--) heapify_4branch(start,ptr,total_elem,size,cmp);
    for (;sorted>start;sorted-=size){
        swap(sorted,start,size);
        heapify_4branch(start,1,--total_elem,size,cmp);
    }
}