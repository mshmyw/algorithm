#include<stdio.h>
#include <stdio.h>

int max(int a, int b){
    /* if(a >= b) */
    /*     return a; */
    /* return b; */
    int diff = a - b;
    return a - ((diff >> 31) & diff);
}

int sub_sum(int a[], int n){
    int cur_sum = 0;
    int res_max = -1000;
    int i;
    for(i = 0; i < n; i++){
        cur_sum = max(cur_sum, 0) + a[i];
        res_max = max(res_max, cur_sum);
    }

    return res_max;
}

int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;

    int max_sum, i;
    int *sum = malloc(sizeof(int) * numsSize);

    sum[0] = nums[0];
    max_sum = nums[0];

    for(i = 1; i < numsSize; i++){
        sum[i] = max(sum[i - 1] + nums[i], nums[i]);
        max_sum = max(max_sum, sum[i]);
    }

    return max_sum;
}

int main(void){
    int a[] = {-1, 2, 4, 7, -4, 6};
    int n = sizeof(a) / sizeof(a[0]);

    int max = sub_sum(a, n);
    printf("max: %d\n", max);
    max = maxSubArray(a, n);
    printf("max: %d\n", max);

    return 0;
}
