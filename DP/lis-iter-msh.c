#include<stdio.h>
#include<stdlib.h>

int max(int a, int b){
    if(a > b)
        return a;

    return b;
}

void print(int *a, int n){
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return;
}

int msh_lis_iter(int *a, int n){
    if(a[0] == '\0')
        return 0;

    int *len = (int *)malloc(sizeof(int) * n);
    int i, j;
    for(i = 0; i < n; i++)
        len[i] = 1;

    for(i = 1; i < n; i++)
        for(j = 0; j < i; j++)
            if(a[j] < a[i])
                len[i] = max(len[i], len[j] + 1);

    print(len, n);
    return len[i - 1];
}

int main(void){

    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);

    msh_lis_iter(arr, n);

    return 0;
}
