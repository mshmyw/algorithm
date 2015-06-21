//file name : regular-match.c
//created at: Sun Jun 21 16:27:23 2015
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

bool is_match(char *s, char *t){
    if(*s == '\0') //total match 's'
        return true;

    if(*t == '?'){
        s++;t++;
        return is_match(s, t);
    }

    if(*t == '*'){  //not greed, just match the first char, for example: 'abca', then match the first 'a'
        t++;
        if(*t == '\0')
            return true;
        while((*s != '\0') && (*s != *t))
            s++;
        if(*s == '\0')
            return false;
        s++;t++;
        return is_match(s, t);
    }

    if(*s == *t){
        s++;t++;
        return is_match(s, t);
    }

    return false;
}
int main(void){
/* isMatch("aa","a") → false */
/* isMatch("aa","aa") → true */
/* isMatch("aaa","aa") → false */
/* isMatch("aa", "*") → true */
/* isMatch("aa", "a*") → true */
/* isMatch("ab", "?*") → true */
/* isMatch("aab", "c*a*b") → false */

    char *s = "aab";
    char *t = "c*a*b";

    bool flag = is_match(s, t);
    if(flag)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}
