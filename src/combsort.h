#pragma once
#include "./bits.h"
#define RATE 1.24

void combsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    unsigned long skip=total_elem,i,j;
    while (skip>1){
        skip=(unsigned long)(((float)skip)/RATE);
        for (i=0;i<skip;i++) for (j=i+skip;j<total_elem;j+=skip) if (cmp(start+j*size,start+(j-skip)*size)<0)
            swap(start+j*size,start+(j-skip)*size,size);
    }
}