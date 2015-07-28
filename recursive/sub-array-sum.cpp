//file name : sub-array-sum.cpp
//created at: Mon Jul 27 19:38:34 2015
//author:  root

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print(vector<int> res){
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "-";
    cout << endl;

    return;
}

void print_vector(vector<vector<int> > all_res){
    for(int i = 0; i < all_res.size(); i++)
        print(all_res[i]);

}

void sub_sum_inner_recur(int *num, int len, int sum, int i, vector<int> &res, vector<vector<int> > &all_res){
    if(i > len)
        return;
    if(sum < 0)
        return;

    if(sum == 0){
        all_res.push_back(res);
        return;
    }

    sub_sum_inner_recur(num, len, sum, i + 1, res, all_res);  //without num[i]
    res.push_back(num[i]);
    sub_sum_inner_recur(num, len, sum - num[i], i + 1, res, all_res); //with num[i]
    res.pop_back();
}

void sub_sum_inner_iter(int *num, int len, int sum, int i, vector<int> &res, vector<vector<int> > &all_res){
    if(i > len)
        return;
    if(sum < 0)
        return;

    if(sum == 0){
        all_res.push_back(res);
        return;
    }

    for(int k = i; k < len; k++){
        res.push_back(num[k]);
        sub_sum_inner_recur(num, len, sum - num[k], k + 1, res, all_res); //with num[i]
        res.pop_back();
    }

    return;
}

void sub_sum(int *num, int len, int sum){
    vector<vector<int> > all_res, all_res2;
    vector<int> res, res2;

    sub_sum_inner_recur(num, len, sum, 0, res, all_res);
    print_vector(all_res);

    printf("--OTHER WAY--\n");

    sub_sum_inner_iter(num, len, sum, 0, res2, all_res2);
    print_vector(all_res2);
    return;
}

int main(void){
    int num[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(num) / sizeof(num[0]);
    int sum = 10;
    sub_sum(num, n, sum);

    return 0;
}
