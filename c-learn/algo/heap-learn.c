//file name : heap-learn.c
//created at: Fri Aug 14 10:29:51 2015
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

#define MAX 100
int heap[MAX];

void adjust_heap(int *heap, int root, int size){
    if(root * 2 > size)
        return;

    int lchild = root * 2;
    int rchild = root * 2 + 1; //may be without right child
    int max_node = root;

    if(heap[lchild - 1] > heap[root - 1])
        max_node = lchild;

    int max_value = max(max(heap[root - 1], heap[lchild - 1]), heap[rchild - 1]);
    if(rchild <= size &&  max_value == heap[rchild - 1])
        max_node = rchild; // the key

    if(max_node == root)
        return;

    swap(&heap[root - 1], &heap[max_node - 1]);
    adjust_heap(heap, max_node, size);

    return;
}

void build_heap(int *heap, int size){
    int i;
    for(i = size / 2; i > 0; i--) //from size / 2 adjust
        adjust_heap(heap, i, size);

    return;
}

void heap_sort(int *heap, int size){
    int i;
    for(i = size; i > 0; i--){
        swap(&heap[0], &heap[i - 1]);
        adjust_heap(heap, 1, i - 1);
    }

    return;
}

int main(void){

    int heap[] = {16, 7, 3, 20, 17, 8};
    int n = sizeof(heap) / sizeof(heap[0]);
    build_heap(heap, n);
    heap_sort(heap, n);
    print(heap, n);

    return 0;
}
