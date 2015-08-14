//file name : count-1-from-1-n.c
//created at: Fri Jul 10 10:35:38 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

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

#define N 100

int count_1(char *str){

    if(*(str + 1) == '\0')
        if(*str != '0')
            return 1;
        else
            return 0;

    int length = strlen(str);
    int num = 0;

    // the first digit
    if(str[0] == '1')
        num = atoi(str + 1) + 1 + count_1(str + 1);
    else if(str[0] != '0')
        num =  pow(10, length - 1) + count_1(str + 1);

    // other digits, except the first digit
    num = num + (str[0] - '0') * (length - 1) * pow(10, length - 2); // combination

    return num;
}

int count_1_in_n(int n){

    char str[N];
    memset(str, 0, sizeof(str));
    sprintf(str, "%d", n);
    printf("str %s\n", str);

    return count_1(str);
}

int main(void){

    int n = 22345;
    int count = count_1_in_n(n);
    printf("count %d\n", count);
    return 0;
}
