//file name : k-min-item.c
//created at: Thu Jul  9 20:42:30 2015
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

int reorder_by_bound(int *a, int left, int right){

    int bound_item = a[left];
    int big_right;
    int big_left = left;

    for(big_right = left + 1; big_right <= right; big_right++)
        if(a[big_right] < bound_item){
            big_left++;
            swap(&a[big_left], &a[big_right]);
        }
    swap(&a[big_left], &a[left]);

    return big_left;
}

void k_min_item_inner(int *a, int left, int right, int k){
    if(left > right) // like this is wrong: left >= right
        return;

    int bound_idx = reorder_by_bound(a, left, right);
    printf("bound-idx %d\n", bound_idx);

    if(bound_idx == k)
        printf("the %d item %d\n", bound_idx, a[k]);
    else if(bound_idx < k)
        k_min_item_inner(a, bound_idx + 1, right, k);  //remeber right bound not contain the bound itself, so bound_idx + 1
    else
        k_min_item_inner(a, left, bound_idx - 1, k);

    return;
}

void k_min_item(int *a, int n, int k){

    assert(a && n > 0 && k > 0);
    k_min_item_inner(a, 0, n - 1, k - 1);

    return;
}

int main(void){

    int a[] = {3, 2, 4, 1, 5};
    /* int a[] = {1, 2}; */
    int n = sizeof(a) / sizeof(a[0]);
    int k = 5;

    k_min_item(a, n, k);

    return 0;
}
