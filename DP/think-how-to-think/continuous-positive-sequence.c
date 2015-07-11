//file name : continuous-positive-sequence.c
//created at: Sat Jul 11 10:47:48 2015
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
int count = 0;
void continuous_positive_sequence(int n){
    int left, right, sum, i;

    left = 1; right = 1 + 1;
    sum = left + right;
    for(; right < n; )
        if(sum == n){
            /* for(i = left; i <= right; i++) */
            /*     printf("%d ", i); */
            /* printf("\n"); */
            count++;

            right++;
            sum = sum + right;
        }
        else if(sum < n){
            right++;
            sum = sum + right;
        }
        else if(sum > n){
            sum = sum - left;
            left++;
        }

    return;
}

int main(void){

    /* int a[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000}; */
       //count: 1   2     3     4     5       6        7          8
    int a[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int n = sizeof(a) / sizeof(a[0]);
    int i, j;
    for(j = 1; j < n + 2; j++)
    for(i = 0; i < n; i++){
        continuous_positive_sequence(a[i] * j);
        printf("%d => %d\n", a[i] * j, count);
        count = 0;
    }
    return 0;
}
