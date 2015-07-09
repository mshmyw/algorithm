#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

// 基于DFS的递归

// 原数组中每一个元素在子集中有两种状态：要么存在、要么不存在。这样构造子集的过程中每个元素就有两种选择方法：选择、不选择，因此可以构造一颗二叉树来表示所有的选择状态：二叉树中的第i+1层第0层无节点表示子集中加入或不加入第i个元素，左子树表示加入，右子树表示不加入。所有叶节点即为所求子集。因此可以采用DFS的递归思想求得所有叶节点。
void subnets(vector<int> &s, vector<int> temp, int level,
             vector< vector<int> > &result){
    if(level == s.size()){
        result.push_back(temp);
        return;
    }

    subnets(s, temp, level + 1, result);
    temp.push_back(s[level]);
    subnets(s, temp, level + 1, result);
    // temp.pop_back(); //here this is not necessary
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

 vector<vector<int> > combination_sum(vector<int>& candidates, int target) {
        vector<vector<int> > allSol;
        vector<int> sol;
        if(candidates.empty()) return allSol;
        sort(candidates.begin(), candidates.end());
        find_comb_sum(candidates, 0, target, sol, allSol);
        return allSol;
    }


int main(void){
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    vector<int> s(array, array + n);
    vector< vector<int> > result;
    vector<int> temp;
    subnets(s, temp, 0, result);

    vector< vector<int> >::iterator it;
    vector<int>::iterator it_inner;
    for(it = result.begin(); it != result.end(); it++){
        for(it_inner = (*it).begin(); it_inner != (*it).end(); it_inner++)
            cout<<*it_inner;

        cout<<endl;
    }

    return 0;
}
