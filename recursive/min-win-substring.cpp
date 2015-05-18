#include <vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

string min_win(string s, string t) {
    int min_win_begin = 0;
    int min_win_end = 0;
    int s_len = s.size();
    int t_len = t.size();
    int need_to_find[256] = {0};

    for(int i = 0; i < t_len; i++)
        need_to_find[t[i]]++;
    int has_find[256] = {0};
    int min_win_len = s.size() + 1;
    int count = 0;

    for(int begin = 0, end = 0; end < s_len; end++){
        if(need_to_find[s[end]] == 0)continue;
        has_find[s[end]]++;
        if(has_find[s[end]] <= need_to_find[s[end]])
            count++;
        
        if(count == t_len){
            while(need_to_find[s[begin]] == 0 ||
                  has_find[s[begin]] > need_to_find[s[begin]]){
                if(has_find[s[begin]] > need_to_find[s[begin]])
                    has_find[s[begin]]--;
                begin++;
            }
        
            int win_len = end - begin + 1;
            if(win_len < min_win_len){
                min_win_begin = begin;
                min_win_end = end;
                min_win_len = win_len;
            }
        }
    }

    cout << " end " << min_win_end << "first " << min_win_begin << endl;
    if((s.size() + 1) == min_win_len)
        return "";
    return s.substr(min_win_begin, min_win_end - min_win_begin + 1);
}

int min_subarray_len(int s, vector<int>& nums){
    int sum = 0;
    int min_len = nums.size();
    int left = 0, right = 0;

    while (right < nums.size()){
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
    // min_subarray_len(s, nums);
    // string str = "ADOBECODEBANC";
    string str = "A";
    string t = "A";
    // string t = "ABC";
    
    string substr = min_win(str, t);
    cout << substr << endl;
    return 0;
}
