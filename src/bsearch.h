#pragma once

void* right_aviliable(void *start,unsigned long total_elem,unsigned long size,int (*check)(const void *)){
    void *end=start+(total_elem)*size,*mid=start+(total_elem/2)*size;
    while (start+size<end){
        if (check(mid)) start=mid;
        else end=mid;
        mid=start+((end-start)/(size*2))*size;
    }
    return start;
}

void* left_aviliable(void *start,unsigned long total_elem,unsigned long size,int (*check)(const void *)){
    start-=size;
    void *end=start+(total_elem)*size,*mid=start+(total_elem/2)*size;
    while (start+size<end){
        if (check(mid)) end=mid;
        else start=mid;
        mid=start+((end-start)/(size*2))*size;
    }
    return end;
}