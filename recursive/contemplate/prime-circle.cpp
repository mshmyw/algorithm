//file name : prime-circle.cpp
//created at: Tue Aug  4 21:14:14 2015
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
bool is_prime(int a, int b){
    int sum = a + b;
    if(sum <= 1)
        return true;

    for(int i = 2; i < sum; i++)
        if((sum % i) == 0)
            return false;

    return true;
}

void prime_circle_inner(int n, int k, vector<bool> &visited, vector<int> &res, vector<vector<int> > &res_all){
    if(k == (n + 1)){
        if(is_prime(res.back(), res.front()) == true && res.size() == n)
            res_all.push_back(res);
        return;
    }

    for(int i = 2; i <= n; i++)
        if(visited[i] == false)
            if(is_prime(res.back(), i) == true){
                visited[i] = true; //set
                res.push_back(i);
                prime_circle_inner(n, i + 1, visited, res, res_all);
                res.pop_back(); //reset
                visited[i] = false; //reset
            }

    return;
}

void prime_circle(int n){
    vector<int> res;
    vector<vector<int> > res_all;
    vector<bool> visited(n + 1);
    res.push_back(1); // the init num
    prime_circle_inner(n,  1, visited, res, res_all);

    for(int i = 0; i < res_all.size(); i++){
        for(int j = 0; j < res_all[i].size(); j++)
            cout <<"  "<< res_all[i][j];
        cout << endl;
    }

    return;
}

int main(void){
    int n = 15;
    for(int i = 2; i < n; i++){
        prime_circle(i);
        cout << "------\n" << endl;
    }
    return 0;
}
