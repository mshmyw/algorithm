//file name : exceed-half-nums.c
//created at: Mon Aug 24 21:04:48 2015
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

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;

    return;
}

void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%3d", a[i]);

    printf("\n");

    return;
}

void exceed_half_nums(int *nums, int n){
    int i;
    int count = 1;
    int candidate = nums[0];
    for(i = 1; i < n; i++)
        if(count == 0){
            candidate = nums[i];
            count++;
        }else if(candidate == nums[i])
            count++;
        else
            count--;

    for(count = 0, i = 0; i < n; i++)
        if(nums[i] == candidate)
            count++;
    if(count > n / 2)
        printf("DST %d\n", candidate);

    return;
}
int main(void){
    int a[] = {2, 3, 3, 2, 2, 4, 2};
    int n = sizeof(a) / sizeof(a[0]);
    exceed_half_nums(a, n);

   return 0;
}
