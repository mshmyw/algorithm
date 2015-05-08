#include<stdio.h>
#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

// 基于DFS的递归

void subnets(vector<int> &s, vector<int> temp, int level,
                 vector< vector<int> > &result){
    if(level == s.size()){
        result.push_back(temp);
        return;
    }

    subnets(s, temp, level + 1, result);
    temp.push_back(s[level]);
    subnets(s, temp, level + 1, result);
}

// 位运算
// 求子集问题就是求组合问题。数组中的n个数可以用n个二进制位表示，当某一位为1表示选择对应的数，为0表示不选择对应的数。
vector< vector<int> > subsets_bit(vector<int> &S,int n){
     //n个数有0~max-1即2^n中组合，1<<n表示2^n
    int max = 1<<n;
    vector<vector<int> >result;

    for(int i = 0;i < max;i++){
        vector<int> temp;
        int idx = 0;
        int j = i;
        while(j > 0){
            //判断最后一位是否为1，若为1则将对应数加入到当前组合中
            if(j&1)
                temp.push_back(S[idx]);
            idx++;
            //判断了这一位是否为1后要右移
            j = j>>1;
        }
        //判断完了一种组合，加入到结果集中
        result.push_back(temp);
    }
    return result;
}

  void find_comb_sum(vector<int> &candidates, int start, int target, vector<int> &sol, vector<vector<int> > &allSol){
        if(target == 0){
            allSol.push_back(sol);
            return;
        }
        if(target < 0)
            return;

        for(int i = start; i < candidates.size(); i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            sol.push_back(candidates[i]);
            find_comb_sum(candidates, i + 1, target - candidates[i], sol, allSol);
            sol.pop_back();
        }


    }

 vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > allSol;
        vector<int> sol;
        if(candidates.empty()) return allSol;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        find_comb_sum(candidates, 0, target, sol, allSol);
        return allSol;

    }



int main(void){
    int array[] = {1, 2, 3, 4};
    int n = sizeof(array) / sizeof(array[0]);
    vector<int> s(array, array + n);
    vector< vector<int> > result;
    vector<int> temp;
    // subnets(s, temp, 0, result);
    // result = subsets_bit(s, n);
    result = combinationSum2(s, 7);
    vector< vector<int> >::iterator it;
    vector<int>::iterator it_inner;
    for(it = result.begin(); it != result.end(); it++){
        for(it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++)
            cout<<*it_inner;

        cout<<endl;
    }

    return 0;
}
