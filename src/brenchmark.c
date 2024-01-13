#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bits.h"
#include "bucketsort.h"
#include "countingsort.h"
#include "heapsort.h"
#include "quicksort.h"
#include "radixsort-MSD.h"
#include "radixsort-LSD.h"
#include "mergesort.h"
#include "shellsort.h"
#include "combsort.h"
#include "insertionsort.h"
#include "patiencesort.h"
#include "cartesianTreesort.h"

void test_insertion(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,2,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    isort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

void test_merge(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,2,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    msort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}


void test_comb(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,1,3,1,2,7,8,10,9,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    combsort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

void test_quick(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,1,3,1,2,7,8,10,9,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    qsort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

void test_patience(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,1,3,1,2,7,8,10,9,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    psort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

void test_cartesiantree(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,1,3,1,2,7,8,10,9,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    ctsort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

void test_copy(){
    int a[]={9,2,5,3,6,4,7,8,1,10,9,3,4,2,5,1,0,4};
    int i,len=sizeof(a)/sizeof(int);
    copy_nbits(a+1,a,7*sizeof(int));
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

int main(){
    test_cartesiantree();
    return 0;
}