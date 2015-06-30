//file name : brother-str.c
//created at: Tue Jun 30 15:35:30 2015
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

#define N 128
/* hash also, you can use sorting */
bool brother_str(char *str1, char *str2){
    int count[2][N];
    int i;

    memset(count, 0, sizeof(count));

    for(i = 0; i < strlen(str1); i++)
        count[0][str1[i]]++;

    for(i = 0; i < strlen(str2); i++)
        count[1][str2[i]]++;

    for(i = 0; i < N; i++)
        if(count[0][i] != count[1][i])
            return false;

    return true;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    char *str1 = "aabb67^";
    char *str2 = "^76baba";

    bool flag = brother_str(str1, str2);

    if(flag)
        printf("%s\t%s\t is brother\n", str1, str2);
    else
        printf("%s\t%s\t is not brother\n", str1, str2);

    return 0;
}
