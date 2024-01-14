#pragma once
#include "./bits.h"
#include "./bsearch.h"
#include "./mergesort.h"
#include <stdlib.h>

typedef enum State{
    Void,Head,Back
}State;

void kuansort_basic(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *queue=malloc(size*total_elem*2),
    *hh=queue+total_elem*size,
    *tt=hh+size,*ptr,*mergeptr1=NULL,*mergeptr2=NULL;
    copy(hh,start,size);
    int check(const void *a){
        return cmp(a,ptr)<=0;
    }
    int state=0;
    for (ptr=start+size;ptr<start+total_elem*size;ptr+=size){
        if (cmp(hh,ptr)>=0) hh-=size,copy(hh,ptr,size);
        else if (cmp(tt-size,ptr)<=0) copy(tt,ptr,size),tt+=size;
        else {
            if (state) merge_basic(mergeptr1,mergeptr2,tt-size,size,cmp);
            mergeptr1=right_aviliable(hh,(tt-hh)/size,size,check);
            mergeptr2=tt-size;
            copy(tt,ptr,size);
            tt+=size;
            state=1;
        }
    }
    merge_basic(mergeptr1,mergeptr2,tt-size,size,cmp);
    for (unsigned long i=0;i<total_elem*size;i+=size) copy(start+i,hh+i,size);
    free(queue);
}

void kuansort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *queue=malloc(size*total_elem*2),
    *hh=queue+total_elem*size,
    *tt=hh+size,*ptr,*mergeptr1=NULL,*mergeptr2=NULL;
    copy(hh,start,size);
    int check(const void *a){
        return cmp(a,ptr)<=0;
    }
    int headstate=0,backstate=0;/*
    for (ptr=start+size;ptr<start+total_elem*size;ptr+=size){
        if (cmp(hh,ptr)>=0) hh-=size,copy(hh,ptr,size);
        else if (cmp(tt-size,ptr)<=0) copy(tt,ptr,size),tt+=size;
        else{
            if (state==Back) merge_basic(mergeptr1,mergeptr2,tt-size,size,cmp);
            else if (state==Head) merge_basic(hh,mergeptr2,mergeptr1,size,cmp);
            mergeptr1=right_aviliable(hh,(tt-hh)/size,size,check);
            if ((mergeptr1-hh)<(tt-mergeptr1)){
                hh-=size;
                mergeptr2=hh;
                copy(hh,ptr,size);
                state=Head;
            }
            else{
                mergeptr2=tt;
                copy(tt,ptr,size);
                tt+=size;
                state=Back;
            }
        }
        if (state==Back) merge_basic(mergeptr1,mergeptr2,tt-size,size,cmp);
        else if (state==Head) merge_basic(hh,mergeptr2,mergeptr1,size,cmp);
        for (unsigned long i=0;i<total_elem*size;i+=size) copy(start+i,hh+i,size);
        //free(queue);
    }*/
}