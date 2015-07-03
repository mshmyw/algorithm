//file name : replace-blank.c
//created at: Fri Jul  3 14:54:00 2015
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

/* what you should care is not what the answer is like, but the idea that how you get it. */
void replace_blank(char *str){
    assert(str);

    int i, j, count_blank = 0;
    for(i = 0; str[i] != '\0'; i++)
        if(str[i] == ' ')
            count_blank++;
    printf("count_blank %d\n", count_blank);

    printf("str %s\n", str);
    for(i = strlen(str) - 1, j = i + count_blank * 2; i >= 0;)
        if(str[i] != ' ')
            str[j--] = str[i--];
        else{
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            i--;
        }
    printf("str %s\n", str);

    return;
}

#define SIZE 216
int main(void){

    char str[SIZE] = "we are happy.";
    replace_blank(str);

    return 0;
}
