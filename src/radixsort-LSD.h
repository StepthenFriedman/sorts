#pragma once
#include <stdlib.h>

void rsort_num_longlong(unsigned long long *a, int len){
    unsigned long long *b = (unsigned long long *)malloc(sizeof(unsigned long long)*len), sum[4][65536]={0};
    int i;
    for (i=0;i<len;i++){
        sum[0][a[i] & 65535]++;
        sum[1][(a[i] >> 16) & 65535]++;
        sum[2][(a[i] >> 32) & 65535]++;
        sum[3][a[i] >> 48]++;
    }
    for (i=1;i<=65535;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (i=len-1;i>-1;i--) b[--sum[0][a[i] & 65535]] = a[i];
    for (i=len-1;i>-1;i--) a[--sum[1][(b[i]>>16) & 65535]] = b[i];
    for (i=len-1;i>-1;i--) b[--sum[2][(a[i]>>32) & 65535]] = a[i];
    for (i=len-1;i>-1;i--) a[--sum[3][b[i]>>48]] = b[i];
    free(b);
}

void rsort_num_long(unsigned long *a, int len){
    unsigned long *b = (unsigned long *)malloc(sizeof(unsigned long)*len), sum[4][256]={0};
    int i;
    for (i=0;i<len;i++){
        sum[0][a[i] & 255]++;
        sum[1][(a[i] >> 8) & 255]++;
        sum[2][(a[i] >> 16) & 255]++;
        sum[3][a[i] >> 24]++;
    }
    for (i=1;i<256;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (i=len-1;i>-1;i--) b[--sum[0][a[i] & 255]] = a[i];
    for (i=len-1;i>-1;i--) a[--sum[1][(b[i]>>8) & 255]] = b[i];
    for (i=len-1;i>-1;i--) b[--sum[2][(a[i]>>16) & 255]] = a[i];
    for (i=len-1;i>-1;i--) a[--sum[3][b[i]>>24]] = b[i];
    free(b);
}

void rsort_longlong(void *start,unsigned long total_elem,unsigned long size,unsigned long long (*cast)(const void *)){
    void *b = (void*)malloc(size*total_elem);unsigned long sum[4][65536]={0};
    unsigned long long temp;
    int i;void *ptr=start,*end=start+(total_elem-1)*size,
               *startb=b,*endb=startb+(total_elem-1)*size;

    for (;ptr<=end;ptr+=size){
        temp=cast(ptr);
        sum[0][temp & 65535]++;
        sum[1][(temp >> 16) & 65535]++;
        sum[2][(temp >> 32) & 65535]++;
        sum[3][temp >> 48]++;
    }
    for (i=1;i<=65535;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[0][cast(ptr) & 65535])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[1][(cast(ptr)>>16) & 65535])*size,ptr,size);
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[2][(cast(ptr)>>32) & 65535])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[3][(cast(ptr)>>48) & 65535])*size,ptr,size);
    free(b);
}

void rsort_4priorities_short(void *start,unsigned long total_elem,unsigned long size,unsigned short(*cast1)(const void *),unsigned short(*cast2)(const void *),unsigned short(*cast3)(const void *),unsigned short(*cast4)(const void *)){
    void *b = (void*)malloc(size*total_elem);unsigned long sum[4][65536]={0};
    int i;void *ptr=start,*end=start+(total_elem-1)*size,
               *startb=b,*endb=startb+(total_elem-1)*size;

    for (;ptr<=end;ptr+=size){
        sum[0][cast4(ptr)]++;
        sum[1][cast3(ptr)]++;
        sum[2][cast2(ptr)]++;
        sum[3][cast1(ptr)]++;
    }
    for (i=1;i<=65535;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[0][cast4(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[1][cast3(ptr)])*size,ptr,size);
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[2][cast2(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[3][cast1(ptr)])*size,ptr,size);
    free(b);
}

void rsort_long(void *start,unsigned long total_elem,unsigned long size,unsigned long (*cast)(const void *)){
    void *b = (void*)malloc(size*total_elem);unsigned long sum[4][256]={0},temp;
    int i;void *ptr=start,*end=start+(total_elem-1)*size,
               *startb=b,*endb=startb+(total_elem-1)*size;

    for (;ptr<=end;ptr+=size){
        temp=cast(ptr);
        sum[0][temp & 255]++;
        sum[1][(temp >> 8) & 255]++;
        sum[2][(temp >> 16) & 255]++;
        sum[3][temp >> 24]++;
    }
    for (i=1;i<=255;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[0][cast(ptr) & 255])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[1][(cast(ptr)>>8) & 255])*size,ptr,size);
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[2][(cast(ptr)>>16) & 255])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[3][(cast(ptr)>>24) & 255])*size,ptr,size);
    free(b);
}

void rsort_4priorities_char(void *start,unsigned long total_elem,unsigned long size,unsigned char(*cast1)(const void *),unsigned char(*cast2)(const void *),unsigned char(*cast3)(const void *),unsigned char(*cast4)(const void *)){
    void *b = (void*)malloc(size*total_elem);unsigned long sum[4][256]={0};
    int i;void *ptr=start,*end=start+(total_elem-1)*size,
               *startb=b,*endb=startb+(total_elem-1)*size;

    for (;ptr<=end;ptr+=size){
        sum[0][cast4(ptr)]++;
        sum[1][cast3(ptr)]++;
        sum[2][cast2(ptr)]++;
        sum[3][cast1(ptr)]++;
    }
    for (i=1;i<=255;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[0][cast4(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[1][cast3(ptr)])*size,ptr,size);
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[2][cast2(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[3][cast1(ptr)])*size,ptr,size);
    free(b);
}