#include<stdio.h>
#include<stdlib.h>



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

#define N 256

int res[N];
int count = 0;
void combinate_sum_inner(int *com, int n, int sum, int i){
    if(sum < 0)
        return;

    if(sum == 0){
        count++;
        print(res, i);
        return;
    }

    int j;
    for(j = 0; j < n; j++){
        res[i] = com[j];
        combinate_sum_inner(com, n, sum - res[i], i + 1);
    }

    return;
}

void combinate_sum(int *com, int n, int sum){

    combinate_sum_inner(com, n, sum, 0);
}

int main(void){
    int com[] = {2, 3, 4};
    int n = sizeof(com) / sizeof(com[0]);
    int sum = 12;
    combinate_sum(com, n, sum);
    printf("count: %d\n", count);
    return 0;
}
