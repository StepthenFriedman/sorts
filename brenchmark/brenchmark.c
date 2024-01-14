#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../src/bits.h"
#include "../src/bucketsort.h"
#include "../src/countingsort.h"
#include "../src/heapsort.h"
#include "../src/quicksort.h"
#include "../src/radixsort-MSD.h"
#include "../src/radixsort-LSD.h"
#include "../src/mergesort.h"
#include "../src/shellsort.h"
#include "../src/combsort.h"
#include "../src/insertionsort.h"
#include "../src/patiencesort.h"
#include "../src/cartesianTreesort.h"
#include "../src/smoothsort.h"
#include "../src/kuansort.h"
#include <limits.h>

int cmp(const void *a,const void *b){
    return *((int*)a)-*((int*)b);
}

unsigned long cast(const void *a){
    return (unsigned long)*((int*)a);
}

int main(){
    freopen("test0.in","r",stdin);
    freopen("test0.out","w",stdout);
    int n;
    scanf("%d",&n);
	int a[n],*i=&a[0];
	for(;i<&a[n-1];i++) scanf("%d",i);
    combsort(a,n,sizeof(int),cmp);
    for(i=a;i<&a[n-1];i++) printf("%d ",*i);
    return 0;
}

/*
test0.in:

rsort_long          0.025s
qsort               0.037s
combsort            0.049s
hsort_4branch       0.067s
hsort_2branch       0.077s
qksort              0.077s
msort               0.168s
isort               0.329s
psort               0.441s
ctsort              0.462s
shellsort           5.382s
kuansort_basic      14.795s

test1.in:

rsort_long          0.025s
qsort               0.033s
combsort            0.053s
hsort_4branch       0.069s
hsort_2branch       0.075s
qksort              0.075s
msort               0.168s
isort               0.321s
psort               0.437s
ctsort              0.462s
shellsort           5.394s
kuansort_basic      13.969s
*/