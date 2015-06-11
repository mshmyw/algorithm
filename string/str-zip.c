//file name : str-zip.c
//created at: Thu Jun 11 21:12:42 2015
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

void str_zip(char *str, int lenth){
    assert(str && lenth);

    printf("--%s--\n", str);

    char *zip_str = (char *)malloc(sizeof(char) * lenth);
    memset(zip_str, 0, sizeof(char) * lenth);
    int zip_count = 0;
    char *p_str;
    for(p_str = str; p_str < str + lenth; p_str++){
        int count = 1;
        while(*p_str == *(p_str + 1)){
            count++;
            p_str++;
        }

        if(count != 1){
            char buf[10];
            memset(buf, 0, 10);
            sprintf(buf, "%d", count);
            for (count = 0; count < strlen(buf); count++)
                zip_str[zip_count++] = buf[count];
        }

        zip_str[zip_count++] = *p_str;
    }

    zip_str[zip_count] = '\0';  //the end flag of string
    printf("--%s--\n", zip_str);
    free(zip_str);
    zip_str = NULL;
    return;
}


int main(void){
    char *str[] = {"adef", "xxxyyyyyyz", "cccddecc", "adef", "pppppppp"};
    int i;
    int n = sizeof(str)/ sizeof(str[0]);
    for (i = 0; i < n; i++) {
            int length = strlen(str[i]);
                str_zip(str[i], length);
    }

    return 0;
}
