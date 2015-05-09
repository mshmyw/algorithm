#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define false 0
#define true  1
typedef int bool;

int sunday_cmp(char *str, char *sub_str){
    int i, j;

    int str_len = strlen(str);
    int substr_len = strlen(sub_str);
    int  next[255];
    for(i = 0; i < 255; i++)
        next[i] = substr_len + 1;
    for(i = 0; i < substr_len; i++)
        next[sub_str[i]] = substr_len - i;

    i = j = 0;
    while(i < (str_len - substr_len)){ //key one
        while(j < substr_len){  // key two
            if(str[i + j] != sub_str[j])
                break;
            j++;
        }
        if(j == substr_len)
            return i;

        int k = substr_len;
        while(k >= 0){
            if(str[i + substr_len] == sub_str[k])
                break;
            k--;
        }
        i = i + substr_len - k;
        /* i += next[str[i + substr_len]]; */ // equal from 85 - 91, get the step length next move
        j = 0;
    }

    return -1;
}

int count_same_char(char *str){
    if(str[0] == '\0')
        return 0;

    int pre = 0;
    int cur = 1;
    int count = 1;

    while(str[cur] != '\0'){

        if(str[pre] != str[cur])
            break;
        count++;
        pre = cur;
        cur++;
    }

    return count;
}

int count_and_say(char *str, int len){
    if(str[0] == '\0')
        return 0;

    int pre = 0;
    int cur = 1;
    int count = 1;
    int k = 0;

    char *p = malloc(sizeof(char) * 100);
    char *q = malloc(sizeof(char) * 100);
    memset(q, 0, 100);
    memset(p, 0, 100);
    int i;
    strcpy(p, str);
    printf("%s \n", p);

    for(i= 0; i < 4; i++){

        while(p[cur] != '\0'){
            if(p[pre] != p[cur]){

                while(count){
                    q[k++] = (count % 10) + '0';
                    count = count / 10;
                }
                q[k++] = p[pre];
                count = 1;
                pre = cur; cur++;
                continue;
            }
            count++;
            pre = cur;
            cur++;
        }

        while(count){
            q[k++] = (count % 10) + '0';
            count = count / 10;
        }

        q[k++] = p[pre];
        q[k] = '\0';

        printf("%s \n", q);
        memset(p, 0, 100);
        strcpy(p, q);
        memset(q, 0, 100);

        pre = 0; cur = 1; count = 1; k = 0;
    }

    return 0;
}

int main(void){
    char *str = "1";
    int len = strlen(str);
    int count = count_and_say(str, len);
    printf("count %d\n", count);

    return 0;
}
