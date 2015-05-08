#include<stdio.h>
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
}
int min_path_sum_inner(vector<vector<int> > &grid, int i, int j, vector<vector<int> > &all_sol){
    if(all_sol[i][j])
        return all_sol[i][j];

    if((i == 0) && (j == 0)){
        all_sol[i][j] = grid[0][0];
        return all_sol[i][j];
    }
    if(i == 0){
        all_sol[i][j] = min_path_sum_inner(grid, i, j - 1, all_sol) + grid[i][j];
        return all_sol[i][j];
    }

    if(j == 0){
        all_sol[i][j] = min_path_sum_inner(grid, i - 1, j, all_sol) + grid[i][j];
        return all_sol[i][j];
    }

    all_sol[i][j] =
        min(min_path_sum_inner(grid, i, j - 1, all_sol),
            min_path_sum_inner(grid, i - 1, j, all_sol))
        + grid[i][j];

    return all_sol[i][j];
}

int min_path_sum(vector<vector<int> > &grid){
     vector< vector<int> > all_sol;
    int n = grid.size();
    if(n == 0)
        return 0;

    vector<int> s(n, 0);
    all_sol.push_back(s);    all_sol.push_back(s);    all_sol.push_back(s);
    int sum = min_path_sum_inner(grid, n - 1, n - 1, all_sol);

    cout<< sum <<endl;
    return sum;
}

int main(void){
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);
    vector<int> s(array, array + n);
    vector< vector<int> > grid;
    grid.push_back(s);    grid.push_back(s);    grid.push_back(s);
    vector< vector<int> > result;
    vector<int> temp;

    min_path_sum(grid);

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
