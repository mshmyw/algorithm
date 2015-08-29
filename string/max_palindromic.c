#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print_substr(char *str, int low, int high){
    int i;
    for(i = low; i <= high; ++i)
        printf("%c", str[i]);

    return;
}

int longest_palinedromic_substr(char *str){

    int max_len = 1;
    int start = 0;
    int len = strlen(str);
    int low, high, i;

    for(i = 1; i < len; ++i){

        low = i - 1;
        high = i;
        while((low >= 0) && (high < len) && (str[low] == str[high])){
            if(high - low + 1 > max_len){
                start = low;
                max_len = high - low + 1;
            }
            low--;
            high++;
        }

        low = i - 1;
        high = i + 1;
        while((low >= 0) && (high < len) && (str[low] == str[high])){
            if(max_len < high - low + 1){
                start = low;
                max_len = high - low + 1;
            }
            low--;
            ++high;
        }
    }

 char *substr = malloc(sizeof(char) * len);
    memset(substr, 0, sizeof(char) * len);
    strncpy(substr, str + start, max_len);
    printf("substr --%s--\n", substr);

    print_substr(str, start, start + max_len - 1);
    return max_len;
}

int main(){
    char *str = "abdmshhsmokko";
    longest_palinedromic_substr(str);

    return 0;
}
