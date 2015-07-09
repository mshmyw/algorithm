//file name : max-sub-array-sum.cpp
//created at: Wed Jul  1 16:00:10 2015
//author:  root

#include<iostream>
#include<vector>
#include<string.h>
#include<malloc.h>


using namespace std;

void max_sub_sum(int *a, int n){
    if(a == NULL)
        return;

    int cur_max = a[0];
    int res_max = a[0];

    for(int i = 1; i < n; i++){
        cur_max = cur_max + a[i];
        cur_max = max(cur_max, a[i]);
        res_max = max(cur_max, res_max);
    }

    cout << "res_max " << res_max << endl;
    return;
}

void max_sub_sum_dp(int *a, int n){
    if(a == NULL)
        return;

    int i;
    int *res_max = (int *)malloc(sizeof(int) * n);
    memset(res_max, 0, sizeof(int) * n);

    int max_final = a[0];
    res_max[0] = a[0];
    for(i = 1; i < n; i++){
        res_max[i] = max(res_max[i - 1] + a[i], a[i]);  // in fact, this still be the current max
        max_final = max(max_final, res_max[i]);
    }

    printf("res_max %d\n", max_final);
    free(res_max);

    return;
}

int main(void){

    // int a[] = {-4 , 3 ,56 , -15 , 34 , 0 , -14 , 4};

    int a [] = {-2, 11, -4, 13, -5, -2};
    int n = sizeof(a) / sizeof(a[0]);

    max_sub_sum(a, n);
    max_sub_sum_dp(a, n);

    return 0;
}
