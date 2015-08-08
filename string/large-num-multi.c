//file name : large-num-multi.c
//created at: Sat Aug  8 11:05:38 2015
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

void swap(char *a, char *b){
    char t = *a;
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

void reverse_str(char *str, int left, int right){
    int i, j;
    for(i  = left, j = right; i < j; i++, j--)
        swap(&str[i], &str[j]);

    return;
}

void large_num_multi(char *num1, int m, char * num2, int n){
    assert(num1 && num2);
    char *res = (char *)malloc(sizeof(char) * (m + n + 1));
    /* memset(res, 0, sizeof(char) * (m + n)); */ // this is wrong
    memset(res, '0', sizeof(char) * (m + n + 1));
    res[m + n] = '\0';

    reverse_str(num1, 0, m - 1);
    reverse_str(num2, 0, n - 1);

    int i, j;
    for(i = 0; i < n; i++){ //num2
        int multi_flag = 0;
        int add_flag = 0;
        for(j = 0; j < m; j++){//num1
            int tmp_multi = (num2[i] - '0') * (num1[j] - '0') + multi_flag;
            multi_flag = tmp_multi / 10;
            tmp_multi = tmp_multi % 10;
            int tmp_add = (res[i + j] - '0') + tmp_multi + add_flag;
            add_flag = tmp_add / 10;
            res[i + j] = (tmp_add % 10) + '0';
        }
        res[i + j] += multi_flag + add_flag;
    }

    reverse_str(res, 0, m + n - 1);
    printf("%s * %s = ", num1, num2);
    printf("%s\n", res);
    free(res);
    return;
}

int main(void){

    /* char * num1 = "11"; // num1 is const string, so can't be changed */
    char num1[100] = "1234567890"; // num1 is const string, so can't be changed
    char num2[100] = "123567899876543210";
    large_num_multi(num1, strlen(num1), num2, strlen(num2));

    return 0;
}
