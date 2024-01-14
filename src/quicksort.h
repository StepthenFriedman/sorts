#pragma once
#include "./bits.h"
#include "./insertionsort.h"
#define SWITCH_TO_INSERSION 20UL

void* mid(const void *a,const void *b,const void *c,int (*cmp)(const void *,const void *)){
    int m=cmp(a,b),n=cmp(b,c),k=cmp(c,a);
    if (m*k>=0) return (void*)a;
    if (m*n>=0) return (void*)b;
    return (void*)c;
}

void quicksort_basic(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
    void *base=start,*i=start,*j=end-size;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort_basic(start,j,size,cmp);
    quicksort_basic(j+size,end,size,cmp);
}

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
    if ((end-start)/size<=SWITCH_TO_INSERSION){
        insertionsort(start,end,size,cmp);
        return;
    }
    swap(mid(start,start+((end-start)/(2*size))*size,end-size,cmp),start,size);
    void *base=start,*i=start,*j=end-size;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort(start,j,size,cmp);
    quicksort(j+size,end,size,cmp);
}

void quicksort_3way(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
    if ((end-start)/size<=SWITCH_TO_INSERSION){
        insertionsort(start,end,size,cmp);
        return;
    }
    swap(mid(start,start+((end-start)/(2*size))*size,end-size,cmp),start,size);
    void *base=start,*i=start,*i2=i+size,*j=end,*j2=j-size;
    while (i2<=j2){
        while (cmp(j2,base)==0&&i2<j2) j2-=size;
        while (cmp(i2,base)==0&&i2<j2) i2+=size;

        if (cmp(i2,base)<0) i+=size,swap(i,i2,size),i2+=size;
        else swap(i2,j2,size);
        if (i2>j2) break;
        if (cmp(j2,base)>0) j-=size,swap(j,j2,size),j2-=size;
        else swap(i2,j2,size);
    }
    swap(base,i,size);
    quicksort_3way(start,i+size,size,cmp);
    quicksort_3way(j,end,size,cmp);
}

void qksort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+total_elem*size,size,cmp);
}