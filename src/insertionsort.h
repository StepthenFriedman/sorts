#pragma once
#include "./bits.h"
#include "./bsearch.h"
#include <stdlib.h>

void insertionsort_basic(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start,*ptr=start+size,*change,*temp=(void*)malloc(size);
    for (;ptr<end;ptr+=size){
        change=ptr;
        copy(temp,change,size);
        while (change>start && cmp(change-size,temp)>0) copy(change,change-size,size),change-=size;
        copy(change,temp,size);
    }
    free(temp);
}

void insertionsort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start,*ptr=start+size,*change,*temp=(void*)malloc(size);
    int check(const void *x){return cmp(x,temp)>=0;}
    for (;ptr<end;ptr+=size) if (cmp(ptr,ptr-size)<0) {
        change=ptr;
        copy(temp,change,size);
        change=left_aviliable(start,(change-start)/size,size,check);
        copy_nbits(change+size,change,(ptr-change));
        copy(change,temp,size);
    }
    free(temp);
}

void isort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    insertionsort(start,start+total_elem*size,size,cmp);
}

void insertionsort_skip(void *start,void *end,unsigned long skip_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start,*ptr=start+size*skip_elem,*change,*temp=(void*)malloc(size);
    for (;ptr<end;ptr+=size*skip_elem){
        change=ptr;
        copy(temp,change,size);
        while (change>start && cmp(change-size*skip_elem,temp)>0) copy(change,change-size*skip_elem,size),change-=skip_elem*size;
        copy(change,temp,size);
    }
    free(temp);
}