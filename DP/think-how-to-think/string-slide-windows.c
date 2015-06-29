//file name : string-slide-windows.c
//created at: Mon Jun 29 10:48:26 2015
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

void len_slide_windows_inner(int *num, int len, int *cur_max_len){
    int i;

    for(i = 0; i < len; i++)
        if(num[i])
            *cur_max_len = *cur_max_len + 1;

    return;
}
int num_slide_windows(int *num, int num_len, int len){
    assert(num);

    if(num_len == 0)
        return 0;

    int i = 0;
    int cur_len = 0;
    int max_len = 0;
    int left = 0, right = 0;
    int slide_len = 0;
    slide_len = len;

    slide_len = min(num_len, slide_len);
    len_slide_windows_inner(num, slide_len, &cur_len);


    if(slide_len == num_len)
        return cur_len;

    for(i = 1; i <= num_len - len; i++){
        left = i; right = len + i;
        if(num[left] && !num[right - 1])
            cur_len--;
        else if(!num[left] && num[right - 1])
            cur_len++;

        max_len = max(cur_len, max_len);
    }

    return max_len;
}
int main(void){

    /* int a[] = {1, 2, 3, 0, 0, 6, 7, 8};  */
    int a[] = {1, 2, 3, 0, 0, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    int len = 4;
    int max_len = num_slide_windows(a, n, len);
    printf("max len %d\n", max_len);
    return 0;
}
