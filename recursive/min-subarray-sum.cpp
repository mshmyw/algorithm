#include <vector>
#include<iostream>
#include<algorithm>

using namespace std;
int min_len;
void min_subarray(int s, int i, vector<int> nums, vector<int> res, vector<vector<int> > & res_all){
    if(i == nums.size())
        return;
    if(s <= 0){
        if(min_len > res.size()){
            min_len = res.size();
            res_all.push_back(res);
        }
        return;
    }

    min_subarray(s, i + 1, nums, res, res_all);
    res.push_back(nums[i]);
    min_subarray(s - nums[i], i + 1, nums, res, res_all);
    return;
}

int min_subarray_len_1(int s, vector<int>& nums){
    vector<int> res;
    vector<vector<int> > res_all;
    min_len = nums.size();
    min_subarray(s, 0, nums, res, res_all);
    vector<int> result = res_all.back();
    for(vector<int>::iterator it = result.begin(); it != result.end(); ++it)
        cout << *it << endl;
    cout << "size" << result.size() << endl;
    return result.size();
}

int min_subarray_len(int s, vector<int>& nums){
    int sum = 0;
    int min_len = nums.size();
    int left = 0, right = 0;

    while (right < nums.size()){  //based slide windows
        while((sum < s) && (right < nums.size())){
            sum += nums[right];
            right++;
        }

        while(sum >= s){
            min_len = min(min_len, right - left);
            sum -= nums[left];
            left++;
        }
    }

    cout << right <<" "<< left <<" "<< min_len <<" "<< endl;
    return min_len;
}

int main()
{
    int s = 7;
    int a[] = {2, 3, 1, 2, 4, 3};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> nums(a, a + n);
    min_subarray_len(s, nums);
    return 0;
}
