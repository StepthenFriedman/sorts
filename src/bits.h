#pragma once

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

void swap(void *a, void *b,unsigned long size){
    if (a==b) return;
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void swap_nbits(void *a, void *b,unsigned long n){
    struct NBits{char x[n];} *ac=a,*bc=b,tmp;
	tmp = *ac;
	*ac = *bc;
    *bc = tmp;
}

typedef struct b256{
    unsigned long long a,b,c,d;
}b256;

void copy_256bits(void *dest, void *src){
    b256 *d=dest,*s=src;
    *d=*s;
}

void copy_nbits(void *dest, void *src,unsigned long n){
    struct NBits{char x[n];} *d=dest,*s=src;
    *d=*s;
}