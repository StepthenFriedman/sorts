#pragma once
#include "./bits.h"
#include "./bsearch.h"
#include "./mergesort.h"
#include <stdlib.h>

void psort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    unsigned long  ulsize=sizeof(unsigned long),
                  *whichHeap=(unsigned long*)calloc(total_elem,ulsize),
                  *whichPlace=(unsigned long*)calloc(total_elem,ulsize),
                  *heapElemCount=(unsigned long*)calloc(total_elem+1,ulsize);
    void *heaptoe=(void*)calloc(total_elem,size),
         *temp=(void*)malloc(total_elem*size),
         *heapHandle;
    unsigned long ptr,heapptr,newptr;
    int heapNum=0;
    int check(const void *x){return cmp(start+ptr*size,x)>=0;}
    for (ptr=0;ptr<total_elem;ptr++){
        heapHandle=left_aviliable(heaptoe,heapNum+1,size,check);
        heapptr=(heapHandle-heaptoe)/size;
        copy(heaptoe+heapptr*size,start+ptr*size,size);
        whichHeap[ptr]=heapptr;
        whichPlace[ptr]=heapElemCount[heapptr]++;
        if (heapptr==heapNum) heapNum++;
    }
    for (heapptr=1;heapptr<=heapNum;heapptr++) heapElemCount[heapptr]+=heapElemCount[heapptr-1];

    for (ptr=0;ptr<total_elem;ptr++){
        newptr=whichPlace[ptr];
        if (whichHeap[ptr]) newptr+=heapElemCount[whichHeap[ptr]-1];
        copy(temp+newptr*size,start+ptr*size,size);
    }
    for (heapptr=0;heapptr<heapNum;heapptr++) merge(temp,temp+size*(heapElemCount[heapptr]-1),temp+size*(heapElemCount[heapptr+1]-1),size,cmp);

    for (ptr=0;ptr<total_elem;ptr++) copy(start+ptr*size,temp+ptr*size,size);
    
    free(whichHeap),free(whichPlace),free(heaptoe),free(temp),free(heapElemCount);
}