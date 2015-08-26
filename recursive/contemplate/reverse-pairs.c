//file name : reverse-pairs.c
//created at: Wed Aug 26 14:27:52 2015
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

void merge_sort_units(int *nums, int left, int mid, int right){
    int *pnums, *pnums1, *pnums2, *pdup;
    int *dup =(int *)malloc(sizeof(int) * (right - left + 1));
    memset(dup, 0, sizeof(int) * (right - left + 1));

    //NOTE: pdup = dup + right is overflow, should be: pudp = dup + right - 1; pnums1 >= nums + left, not pnums1 >= nums
    for(pnums1 = nums + mid, pnums2 = nums + right, pdup = dup + right - left; (pnums1 >= nums + left) && (pnums2 >= nums + mid + 1); ) //sort
        *pdup-- = (*pnums1 > *pnums2 ? *pnums1-- : *pnums2--);
    while(pnums1 >= nums + left) *pdup-- = *pnums1--;  //sort the remained
    while(pnums2 >= nums + mid + 1) *pdup-- = *pnums2--;

    for(pnums = nums + left, pdup = dup; pnums <= nums + right; ) //copy back to nums
        *pnums++ = *pdup++;

    free(dup); dup = NULL;
    return;
}

void merge_sort(int *nums, int left, int right){
    if(left >= right)
        return;

    int mid = left + (right - left) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge_sort_units(nums, left, mid, right);

  return;
}

void reverse_pairs(int *nums, int n){
    //TODO reverse pairs
    merge_sort(nums, 0, n - 1);
    return;
}
int main(void){
    int a[] = {7, 5, 6, 4};
    int n = sizeof(a) / sizeof(a[0]);
    reverse_pairs(a, n);
    print(a, n);
    return 0;
}
