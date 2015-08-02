/* 最长递增子序列（LIS）的问题是要找到一个给定序列的最长子序列的长度，使得子序列中的所有元素被排序的顺序增加。 */
/* 例如，{10，22，9，33，21，50，41，60，80}  LIS的长度是6和 LIS为{10，22，33，50，60，80}。 */
/* 最优子结构： */
/* 对于长度为N的数组A[N] = {a0, a1, a2, …, an-1}，假设假设我们想求以aj结尾的最大递增子序列长度，设为L[j]，那么L[j] = max(L[i]) + 1, where i < j && a[i] < a[j], 也就是i的范围是0到j – 1。这样，想求aj结尾的最大递增子序列的长度，我们就需要遍历j之前的所有位置i（0到j-1），找出a[i] < a[j]，计算这些i中，能产生最大L[i]的i，之后就可以求出L[j]。之后我对每一个A[N]中的元素都计算以他们各自结尾的最大递增子序列的长度，这些长度的最大值，就是我们要求的问题——数组A
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
