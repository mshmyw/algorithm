//file name : max-common-subchars.c
//created at: Fri Aug 21 11:07:55 2015
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

void longest_common_substr(char *str1, char *str2){
    int i,j, max_len = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **res = (int **)malloc(sizeof(int *) * (len1 + 1)); //malloc two dimension array
    for(i = 0; i < len1 + 1; i++){
        res[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        memset(res[i], 0, sizeof(int) * (len2) + 1);
    }

    for(i = 0; i < len2 + 1; i++)
        res[0][i] = 0;
    for(i = 0; i < len1 + 1; i++)
        res[i][0] = 0;
    for(i = 0; i < len1; i++)
        for(j = 0; j < len2; j++)
            if(str1[i] == str2[j]){
                res[i + 1][j + 1] = res[i][j] + 1;
                max_len = max(max_len, res[i + 1][j + 1]);
            }
    
    for(i = 0; i < len1 + 1; i++){
        print(res[i], len2 + 1);
    }
    printf("MAX LEN : %d\n", max_len);

    for(i = 0; i < len1 + 1; i++) //free memory
        free(res[i]);
    free(res);
    return;
}

int main(void){
    char *str1 = "acbac";
    char *str2 = "acaccbabbcbac";

    longest_common_substr(str1, str2);
    return 0;
}
