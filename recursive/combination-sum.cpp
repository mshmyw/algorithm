#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target){
        vector<vector<int> > allSol;
        vector<int> sol;
        if(candidates.empty()) return allSol;
        sort(candidates.begin(), candidates.end());
        find_comb_sum(candidates, 0, target, sol, allSol);
    }
    void find_comb_sum(vector<int> &candidates, int start, int target, vector<int> &sol, vector<vector<int> > &allSol){
        if(target == 0){
            allSol.push_back(sol);
            return;
        }
        if(target < 0)
            return;

        for(int i = start; i < candidates.size(); i++){
            if((i > start) && (candidates[i] == candidates[i - 1]))
                continue;
            sol.push_back(candidates[i]);
            find_comb_sum(candidates, i, target - candidates[i], sol, allSol);
            sol.pop_back();
        }

    }
};
