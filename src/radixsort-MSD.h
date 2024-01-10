#pragma once
#include <stdlib.h>
#include <string.h>

void radixsort_char(void *start,void *end,void *startb,void *endb,unsigned long size,unsigned long digit,unsigned long *sum,unsigned char(*cast)(const void *,const unsigned long)){
    memset(sum,0,256*sizeof(unsigned long));
    unsigned long dsct_len=(((end-start)/size)+1)/2,
                 *dsct_pos = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                 *dsct_num = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                  dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr,digit)]++;
    for (i=1;i<=255;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr,digit)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) radixsort_char(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),startb+dsct_pos[i],startb+(dsct_pos[i]+dsct_num[i]),size,digit+1,sum,cast);
    free(dsct_pos),free(dsct_num);
}

void rsort_char(void *start,unsigned long total_elem,unsigned long size,unsigned char(*cast)(const void *,const unsigned long)){
    void *startb = (void*)malloc(size*total_elem);
    unsigned long *sum=malloc(sizeof(unsigned long)*256);
    radixsort_char(start,start+total_elem*size,startb,startb+total_elem*size,size,0,sum,cast);
    free(startb),free(sum);
}
