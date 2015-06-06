#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define N 8

typedef int bool;

int queen[N+1][N + 1];

void init(int len1, int len2){
    int i, j;

    for(i = 1; i <= len1; i++)
        for(j = 1; j <= len2; j++)
            queen[i][j] = 0;

    return;
}

void print(int len1, int len2){
    int i, j;

    for(i = 1; i <= len1; i++){
        for(j = 1; j <= len2; j++)
            printf("%3d", queen[i][j]);
        printf("\n");
    }

    return;
}
//judge the position (m, n) is valid.
bool is_valid(int m, int n){  //note: every line just put one
    int i, j;
    for(i = 1; i < m; i++)
        for(j = 1; j <= N; j++)
            if((abs(m -i) == abs(n - j)) || (n == j))
                if(queen[i][j] == 1)
                    return false;
    return true;
}
int count = 0;
void eight_queen(int i){

    if(i == N + 1){
        print(N, N);
        printf("-%d-\n", ++count);
        return;
    }
    int j;
    for(j = 1; j <= N; j++){
        queen[i][j] = 1; // first try, then judge if it's legal;
        if(is_valid(i, j) == true)
            eight_queen(i + 1);
        queen[i][j] = 0;
    }

    return;
}

int main(void){

    init(N, N);
    eight_queen(1);
    return 0;
}
