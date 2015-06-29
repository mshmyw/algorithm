//file name : longest-palindrome.c
//created at: Mon Jun 29 09:35:08 2015
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

int longest_palindrome(char *str, int len){
    int i, left = 0, right = 0;
    int max_lenth = 0, cur_lenth = 0;

    if(*str == '\0')
        return 0;
    if(*(str + 1) == '\0')
        return 1;

    printf("len %d\n", len);

    for(i = 1; i < len; i++){

        left = i - 1; right = i;
        for(; left >= 0 && right < len; left--, right++)
            if(str[left] != str[right]){
                cur_lenth = right - left - 1;
                break;
            }
        if(left < 0 || right >= len)
            cur_lenth = right - left - 1;
        max_lenth = max(max_lenth, cur_lenth);

        if(i + 1 >= len)
            break;
        left = i - 1; right = i + 1;
        for(; left >= 0 && right < len; left--, right++)
            if(str[left] != str[right]){
                cur_lenth = right - left - 1;
                break;
            }
        if(left < 0 || right >= len)
            cur_lenth = right - left - 1;
        max_lenth = max(max_lenth, cur_lenth);
    }

    printf("max %d\n", max_lenth);

    return max_lenth;
}

int main(void){

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);

    char *str = "aabchfhhfmmnnmmokkmmnm";
    longest_palindrome(str, strlen(str));

    return 0;
}
