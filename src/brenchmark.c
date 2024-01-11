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
#include "insertionsort.h"


void test_insertion(){
    int cmp(const void *a,const void *b){
        return *((int*)a)-*((int*)b);
    }
    int a[]={9,2,5,3,6,4,7,8,1};
    int i,len=sizeof(a)/sizeof(int);
    insertionsort(a,a+len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

void test_copy(){
    int a[]={9,2,5,3,6,4,7,8,1,10,9,3,4,2,5,1,0,4};
    int i,len=sizeof(a)/sizeof(int);
    copy_nbits(a+1,a,7*sizeof(int));
    for (i=0;i<len;i++) printf("%d ",a[i]); putchar('\n');
}

int main(){
    test_insertion();
    return 0;
}