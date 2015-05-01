#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define false 0
#define true  1
typedef int bool;

/* int str_sunday(char *str, char *sub_str){ */
/*     int i, j; */
/*     int str_len = strlen(str); */
/*     int substr_len = strlen(sub_str); */
/*     int m = str_len -1; */
/*     int k = substr_len - 1; */

/*     i = 0; j = 0; */
/*     int idx = i; */

/*     while((i < str_len) && (j < substr_len)){ */
/*         if(str[i] == sub_str[j]){ */
/*             j++;i++; */
/*         }else{ */
/*             int t = substr_len - 1; */
/*             while((t >= 0) && (str[m + 1] != sub_str[t])) */
/*                 t--; */
/*             int gap = substr_len - t; */
/*             i += gap; */
/*             j = 0; */
/*             m = i + substr_len - 1; */
/*             idx = i; */
/*         } */
/*     } */

/*     if(i <= str_len) */
/*         return idx; */

/*     return -1; */
/*     /\* while(1){ *\/ */
/*     /\*     while((i < str_len) && (j < substr_len)){ *\/ */
/*     /\*         if(str[i] != sub_str[j]) *\/ */
/*     /\*             break; *\/ */
/*     /\*         j++;i++; *\/ */
/*     /\*     } *\/ */
/*     /\*     if(j == substr_len) *\/ */
/*     /\*         return true; *\/ */
/*     /\*     if(i == str_len) *\/ */
/*     /\*         return false; *\/ */

/*     /\*     m = substr_len - j + i; *\/ */
/*     /\*     k = substr_len - 1; *\/ */
/*     /\*     while(k >= 0){ *\/ */
/*     /\*         if(sub_str[k] == str[m]) *\/ */
/*     /\*             break; *\/ */
/*     /\*         k--; *\/ */
/*     /\*     } *\/ */

/*     /\*     i = m - k; *\/ */
/*     /\*     j = 0; *\/ */
/*     /\* } *\/ */

/*     /\* return false; *\/ */
/* } */

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
int main(void){
    char *str = "lessons tearned in sortware te";
    char *sub_str = "sortware";

int is_exist = sunday_cmp(str, sub_str);
printf("is_exist %d\n", is_exist);

    return 0;
}
