//file name : rmq.c
//created at: Tue Jun  9 21:11:51 2015
//author:  root

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

#define N 10
int max_rmq[N][3];

void rmq_preprocess(int *a){
    int i,j;

    for(i = 0; i < N; i++)
        max_rmq[i][0] = a[i];  //init

    for (j = 1; (1 << j) <= N; j++)  //nice: (1 << j) <= N
        for (i = 1; (i + (1 << j) - 1) <= N; i++) //nice: (i + (1 << j) - 1) <= N
                max_rmq[i][j] = max(max_rmq[i][j - 1], max_rmq[i + (1 << (j - 1))][j - 1]);

    return;
}

int rmq_query(int m, int n){

    int k = (int)(log((n - m + 1) * 1.0) / log(2.0));

    return max(max_rmq[m][k], max_rmq[n - (1 << k) + 1][k]);
}

int main(void){
    int a[] = {3, 4, 5, 7, 8, 9, 0, 3, 4, 5};
    rmq_preprocess(a);
    printf("--%d--\n", rmq_query(0, 2));
    printf("--%d--\n", rmq_query(6, 6));

    return 0;
}
