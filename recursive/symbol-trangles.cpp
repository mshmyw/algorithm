//file name : symbol-trangles.cpp
//created at: Tue Jul 28 11:02:07 2015
//author:  root

#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

void print(vector<int> res){
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "  ";
    cout << endl;

    return;
}

void print_bool(bool *res, int n){
    for(int i = 0; i < n; i++)
        if(res[i])
            printf("+");
        else
            printf("-");

    printf("\n");
    return;
}
void print_sym_iter(vector<vector<bool> > &trangle){
    int n = trangle.size();

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j <= i; j++)
        if(trangle[i][j])
            printf("+");
        else
            printf("-");
        printf("\n");
    }

    return;
}

int total_kinds = 0;
void print_sym(bool *res, int n){
    vector<vector<bool> > trangle(n);
    int total_add = 0;
    for(int j = 0; j < n; j++){
        if(res[j])
            total_add++;
        trangle[n - 1][j] = res[j];
    }
    // print_bool(res, n);
    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            if(trangle[i + 1][j] == trangle[i + 1][j + 1]){
                trangle[i][j] = true;
                total_add++;
            }
            else
                trangle[i][j] = false;

    if(total_add * 2 * 2 != n * (n + 1))
        return;
    total_kinds++;
    printf("====RESULT====%d=\n", total_add);
    print_sym_iter(trangle);
    return;
}

void symbol_trangles_track(int n, int k, bool *res, vector<vector<bool> > &all_res){
    if(k == n){
        print_sym(res, n);
        return;
    }

   for(int i = k; i < n; i++){
        res[i] = true;
        symbol_trangles_track(n, i + 1, res, all_res);
        res[i] = false;
    }

    symbol_trangles_track(n, n, res, all_res);

    return;
}

void symbol_trangles(int n){
    vector<vector<bool> > all_res;
    bool res[n];
    int start = 0;

   symbol_trangles_track(n, start, res, all_res);
   printf("total kindle: %d---\n", total_kinds);

    return;
}

int main(void){
    int n = 4;
    symbol_trangles(n);

    return 0;
}
