//file name : bit-map.c
//created at: Sun Jun 14 10:58:28 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int bool;
#define true 1
#define false 0

int max(int a, int b){
    if(a > b)
        return a;

    return b;
}

int min(int a, int b){
    if(a < b)
        return a;

    return b;
}

#define SHIFT 5
#define N 10000000

int a[1 + N / (1 << SHIFT)];

void set(int i){ //set the iTH as 1

    a[i >> SHIFT] |= (1 << (i & ((1 << SHIFT) - 1)));

    return;
}

void clr(int i){ //clear the iTH as zero

    a[i >> SHIFT] &= ~(1 << (i & ((1 << SHIFT) - 1)));

    return;
}

int test(int i){ // test the iTH if is 1

    return a[i >> SHIFT] & (1 << (i & ((1 << SHIFT) - 1)));
}

int main(void){
    int i;
    for(i = 0; i < N; i++)
        clr(i);

    int num[] = {1, 8888888, 2, 3, 4, 222, 444, 6666, 999, 8888888, 5555};
    int count = sizeof(num) / sizeof(num[0]);

    for(i = 0; i < count; i++){
        if(test(num[i])){
                printf("find %d\n", num[i]);
                break;
            }
        set(num[i]);
    }

    for(i = 0; i < N; i++)
        if(test(i))
            printf("%d\n", i);

    return 0;
}
