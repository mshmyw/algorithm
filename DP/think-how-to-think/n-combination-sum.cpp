//file name : n-combination-sum.cpp
//created at: Thu Jul  2 10:57:49 2015
//author:  root

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void print(vector<int> res){
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "  ";
    cout << endl;

    return;
}

void n_combination_sum_inner(int n, int cur, vector<int> res){
    if(n < 0)
        return;

    if(n == 0){
        print(res);
        return;
    }

    for(int i = cur; i <= n; i++){
        res.push_back(i);
        n_combination_sum_inner(n - i, i, res);  //from i begin, so only the iTH repeat, avoid other repeat use.
        res.pop_back();
    }

    return;
}
void n_combination_sum(int n){
    vector<int> res;
    int cur = 1;
    n_combination_sum_inner(n, cur, res);

    return;
}
int main(void){
    int n = 40;

    n_combination_sum(n);

    return 0;
}
