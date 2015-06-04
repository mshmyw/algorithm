#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a, int b){
    if(a > b)
        return b;

    return a;
}

int dp[100][100]; // dp[i][j, here i, j mean the length of str1 and str2, not the index of them
void print(int len1, int len2){
    int i, j;

    for(i = 0; i <= len1; i++){
        for(j = 0; j <= len2; j++)
            printf("%3d", dp[i][j]);
        printf("\n");
    }
    return;
}
int get_distance_dp(char *str1, char *str2){
    if((str1 == NULL) && (str2 == NULL))
        return 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if(!len1)
        return len2;
    if(!len2)
        return len1;


    memset(dp, 0, sizeof(dp));

    int i, j;
    for(i = 0; i <= len1; i++)
        dp[i][0] = i;
    for(j = 0; j <= len1; j++)
        dp[0][j] = j;

    for(i = 1; i <= len1; i++)
        for(j = 1; j <= len2; j++){
            if(str1[i - 1] == str2[j - 1]) // the index of str1 and str2 when length is i, and j
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    print(len1, len2);

    return  dp[len1][len2];
}

int main(void){
    char *str1 = "efsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdefgefsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdefg";
    char *str2 = "efsdfdabcdefgaabcdefgaaefsdfdabcdefgaabcdefgaabcdefgaabcdefgasfabcdabcdefggaabcdefgasfabcdefg";

    int distance = get_distance_dp(str1, str2);
    printf("distance is %d\nsimilar degrees --%f--\n", distance, 1.0 / (double) (distance + 1));

    return 0;
}
