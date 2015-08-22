//file name : ai=i.c
//created at: Sat Aug 22 16:07:45 2015
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

void  find_all(int *a, int mid, int left, int right){
    int i;

    for(i = mid; i >= left; i--){
        if(a[i] != i)
            break;
        printf("(%d %d) ", i, a[i]);
    }


    for(i = mid + 1; i <= right; i++){
        if(a[i] != i)
            break;
        printf("(%d %d) ", i, a[i]);
    }


    return;
}

void ai_equal_i(int *a, int n){
    int left, right, mid;

    for(left = 1, right = n - 1; left <= right;){
        mid = left + (right - left) / 2;
        if(a[mid] < mid)
            left = mid + 1;
        else if(a[mid] > mid)
            right = mid - 1;
        else{
            find_all(a, mid, left, right);
            return;
        }
    }

    printf("NO EXITST\n");
    return;
}

int main(void){

    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    /* int a[] = {0, -1, 0, 1, 4, 6, 7, 9}; // expect 4 */
    /* int a[] = {0, -1, 0, 1, 4, 5, 7, 9}; //expect 4 5 */
    /* int a[] = {0, -1, 0, 1, 2, 3}; //expect NO */
    /* int a[] = {0, 2, 3, 4, 6, 7}; //expect NO */
    int n = sizeof(a) / sizeof(a[0]);
    ai_equal_i(a, n);

    return 0;
}
