//file name : nine-nums.c
//created at: Fri Jul 31 08:23:40 2015
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
        printf("%d ", a[i]);
    printf("\n");
    return;
}

bool unique_num(int tmp){
    char str[10];
    memset(str, 0, sizeof(str));
    sprintf(str, "%d", tmp);
    int len = strlen(str);
    int hash[11];
    memset(hash, 0, sizeof(hash));
    int i;
    for(i = 0; i < 10; i++)
        hash[str[i] - '0']++;

    for(i = 1; i < 10; i++)
        if(hash[i] > 1)
            return false;

    return true;
}
void get_valid_nums(int *pre_num, int pre_count, int i, int **cur_num, int *cur_count){

    int m, n, tmp, count = 0;
    for(m = 0; m < pre_count; m++)
        for(n = 1; n < 10; n++){
            tmp = pre_num[m] * 10 + n;
            if((tmp % i) == 0 && unique_num(tmp) == true)
                count++;
        }

    *cur_count = count;
    *cur_num = (int *)malloc(sizeof(int) * count);
    memset(*cur_num, 0, sizeof(int) * count);
    if(*cur_num == NULL){
        printf("malloc failed cur num\n");
        exit(0);
    }

    count = 0;
    for(m = 0; m < pre_count; m++)
        for(n = 1; n < 10; n++){
            tmp = pre_num[m] * 10 + n;
            if((tmp % i) == 0 && unique_num(tmp) == true){// NOTE1
                (*cur_num)[count++] = tmp;
            }
        }

     return;
}

void nine_nums_inner(int *pre_num, int pre_count, int i, int n){
    if(i > n){
        printf("-i-%d-count-%d-\n", i, pre_count);
        print(pre_num, pre_count);
        return;
    }
    int *cur_num;
    int cur_count = 0;
    get_valid_nums(pre_num, pre_count, i, &cur_num, &cur_count);  //the core
    nine_nums_inner(cur_num, cur_count, i + 1, n);
    free(cur_num);
    return;
}

void nine_nums(int n){
    int pre_num[] = {0};//NOTE2
    int pre_count = sizeof(pre_num) / sizeof(pre_num[0]);
    nine_nums_inner(pre_num, pre_count, 1, n);
    return;
}

int main(void){
    int a[] = {1, 2, 3, 4, 5 ,6, 7, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int i;
     for(i = 0; i < n; i++)
        nine_nums(a[i]);

    return 0;
}
