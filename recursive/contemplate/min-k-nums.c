//file name : min-k-nums.c
//created at: Tue Aug 25 20:13:18 2015
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

int *split_nums(int *pl, int *pr){
    int *psplit, *pleft, *pright;
    psplit = pl;
    pleft = pl;
    for(pright = pl + 1; pright <= pr; pright++)
        if(*pright < *psplit){
            pleft++;
            swap(pleft, pright);
        }

    swap(psplit, pleft);

    return pleft;
}

void min_k_nums_inner(int *pl, int *pr, int *pk){
    if(pl >= pr) //NOTE must great or equal, can't be just equal
        return;

    int *psplit = split_nums(pl, pr);
    if(pk > psplit)
        min_k_nums_inner(psplit + 1, pr, pk);
    else if(pk < psplit)
        min_k_nums_inner(pl, psplit - 1, pk);
    else
        printf("-%d-OK\n", *psplit);
    return;
}

void min_k_nums(int *nums, int n, int k){
    assert(nums && n > 0);

    min_k_nums_inner(nums, nums + n - 1, nums + k - 1);
    return;
}

void adjust(int *nums, int root, int size){
    if(root * 2 > size)
        return;

    int lchd, rchd, max_node;
    lchd = root * 2;
    rchd = root * 2 + 1;
    max_node = root;
    if(nums[root - 1] < nums[lchd - 1])
        max_node = lchd;
    if(rchd <= size && nums[lchd - 1] < nums[rchd - 1] && nums[root - 1] < nums[rchd - 1])
        max_node = rchd;

    if(max_node != root){
        swap(&nums[root - 1], &nums[max_node - 1]);
        adjust(nums, max_node, size);
    }

    return;
}

void build_heap(int *nums, int n){
    int i;

    for(i = n / 2; i > 0; i--)
        adjust(nums, i, n);

    return;
}

void heap_sort(int *nums, int n, int k){
    int i;
    for(i = n - 1; i >= k; i--)
        if(nums[i] < nums[0]){
            swap(&nums[0], &nums[i]);
            adjust(nums, 1, k);
        }
    return;
}

void min_k_use_heap(int *nums, int n, int k){

    build_heap(nums, k);
    printf("bulid sort:\n");
    print(nums, n);
    heap_sort(nums, n, k);
    return;
}
int main(void){

    int a[] = {3, -2, 4, 1, 44, 2, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = n - 1;

    /* min_k_nums(a, n, k); */ //use quick sort O(n)
    /* print(a, n); */
    min_k_use_heap(a, n, k); //use heap sort O(nlogk)
    print(a, n);
    return 0;
}
