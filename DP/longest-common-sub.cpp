#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;

int longest_common_sub(string str1, string str2){
    int dp[1000][1000];
    memset(dp, 0, sizeof(dp));
    //    vector<vector<int> > dp;
    int i, j;
    for(i = 0; i < str1.size(); i++)
        dp[i][0] = 0;
    for(i = 0; i < str2.size(); i++)
        dp[0][i] = 0;
    for(i = 1; i <= str1.size(); ++i)
        for(j = 1; j <= str2.size(); ++j){
            if(str1[i] == str2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }

    for(i = 0; i <= str1.size(); ++i){
        for(j = 0; j <= str2.size(); ++j)
            cout<<dp[i][j]<<" ";
        cout << endl;
    }
    return dp[i - 1][j - 1];
}

int main(){
    string str1 = "abcbdab";
    string str2 = "bdcaba";

    int max_len = longest_common_sub(str1, str2);
    cout << max_len << " --" << endl;
    return 0;
}
