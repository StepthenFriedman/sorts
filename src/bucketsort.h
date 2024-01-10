#pragma once
#include "./bits.h"
#include <stdlib.h>
#include "./quicksort.h"

void bsort_char(void *start,unsigned long total_elem,unsigned long size,unsigned char(*cast)(const void *),int (*cmp)(const void *,const void *)){
    int sum[256]={0};
    void *startb = (void*)malloc(size*total_elem),*end=start+total_elem*size,*endb=startb+total_elem*size;
    unsigned long *dsct_pos = (unsigned long*)calloc(total_elem/2,sizeof(unsigned long)),
                  *dsct_num = (unsigned long*)calloc(total_elem/2,sizeof(unsigned long)),
                   dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr)]++;
    for (i=1;i<256;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) quicksort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),size,cmp);
    free(dsct_pos),free(dsct_num),free(startb);
}

void bsort_short(void *start,unsigned long total_elem,unsigned long size,unsigned short(*cast)(const void *),int (*cmp)(const void *,const void *)){
    int sum[65536]={0};
    void *startb = (void*)malloc(size*total_elem),*end=start+total_elem*size,*endb=startb+total_elem*size;
    unsigned long dsct_len=((end-start)/size+1)/2,
                 *dsct_pos = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                 *dsct_num = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                  dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr)]++;
    for (i=1;i<65536;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) quicksort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),size,cmp);
    free(dsct_pos),free(dsct_num),free(startb);
}

void bsort_E6(void *start,unsigned long total_elem,unsigned long size,unsigned long(*cast)(const void *),int (*cmp)(const void *,const void *)){
    unsigned char* sum=calloc(1000000,sizeof(unsigned char));
    void *startb = (void*)malloc(size*total_elem),*end=start+total_elem*size,*endb=startb+total_elem*size;
    unsigned long dsct_len=((end-start)/size+1)/2,
                 *dsct_pos = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                 *dsct_num = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                  dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr)]++;
    for (i=1;i<1000000;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) quicksort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),size,cmp);
    free(dsct_pos),free(dsct_num),free(sum),free(startb);
}