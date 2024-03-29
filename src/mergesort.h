#pragma once
#include "./bits.h"
#include "./insertionsort.h"
#include <stdlib.h>
#define SWITCH_TO_INSERSION 20UL

void merge_basic(void *start,void *mid,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *temp=malloc(end-start+size);
    void *i=start,*j=mid+size,*cpy=temp,*fre=temp;
    while (i<=mid&&j<=end){
        if (cmp(i,j)<0) copy(temp,i,size),temp+=size,i+=size;
        else            copy(temp,j,size),temp+=size,j+=size;
    }
    while (i<=mid) copy(temp,i,size),temp+=size,i+=size;//need optimisation
    while (j<=end) copy(temp,j,size),temp+=size,j+=size;//need optimisation
    for (i=start;i<=end;i+=size,cpy+=size) copy(i,cpy,size);
    free(fre);
}
void mergesort_basic(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    void* mid=start+((end-start)/(2*size))*size;
    mergesort_basic(start,mid,size,cmp);
    mergesort_basic(mid+size,end,size,cmp);
    merge_basic(start,mid,end,size,cmp);
}

void merge(void *start,void *mid,void *end,void *temp,unsigned long size,int (*cmp)(const void *,const void *)){
    void *i=start,*j=mid+size,*cpy=temp;
    while (i<=mid&&j<=end){
        if (cmp(i,j)<0) copy(temp,i,size),temp+=size,i+=size;
        else            copy(temp,j,size),temp+=size,j+=size;
    }
    while (i<=mid) copy(temp,i,size),temp+=size,i+=size;//need optimisation
    while (j<=end) copy(temp,j,size),temp+=size,j+=size;//need optimisation
    for (i=start;i<=end;i+=size,cpy+=size) copy(i,cpy,size);
}
void mergesort(void *start,void *end,void *temp,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    if ((end-start)/size<=SWITCH_TO_INSERSION){
        insertionsort(start,end+size,size,cmp);
        return;
    }
    void* mid=start+((end-start)/(2*size))*size;
    mergesort(start,mid,temp,size,cmp);
    mergesort(mid+size,end,temp,size,cmp);
    merge(start,mid,end,temp,size,cmp);
}

void msort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *temp=malloc(size*total_elem);
    mergesort(start,start+(total_elem-1)*size,temp,size,cmp);
    free(temp);
}