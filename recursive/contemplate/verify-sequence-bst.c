//file name : verify-sequence-bst.c
//created at: Thu Jul  9 15:35:04 2015
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

bool verify_seqence_bst(int sequence[], int left, int right){
    if(left >= right)
        return true;

     int root = sequence[right];
    int i;
    for(i = left; i < right; i++)
        if(sequence[i] > root)
            break;
    int j;
    for(j = i; j < right; j++)
        if(sequence[j] < root)
            return false;

    bool left_flag = verify_seqence_bst(sequence, left, i - 1);
    bool right_flag = verify_seqence_bst(sequence, j, right - 1);
    return left_flag && right_flag;
}

bool verify_seqence(int sequence[], int length){
    assert(sequence && length > 0);

   return verify_seqence_bst(sequence, 0, length - 1);
}

int main(void){

    int a[] = {5, 7, 6, 9, 11, 10, 8};
   /* int a[] = {7, 4, 6, 5}; */
    int n = sizeof(a) / sizeof(a[0]);

    if(verify_seqence(a, n))
        printf("RIGHT: IT'S BST\n");
    else
        printf("WRONG: IT'S NOT BST\n");
    return 0;
}
