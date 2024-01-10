#pragma once
#include "./bits.h"

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
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
void qsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+total_elem*size,size,cmp);
}