#pragma once
#include "./bits.h"
#include <stdlib.h>
#include "./insertionsort.h"

void shsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    unsigned long gap,i;
    void *end=start+total_elem*size;
    for (gap=size/2;gap>0;gap/=2) for (i=0;i<gap;i++) insertionsort_skip(start+size*i,end,gap,size,cmp);
}
