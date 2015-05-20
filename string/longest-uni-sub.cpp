#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;

int longest_sub(string str){
    bool visited[256];

    for(int i = 0; i < 256; i++)
        visited[i] = false;
    int max_len = 0;
    int left = 0, right = 0;
    int longest_left = 0;
    int longest_right = 0;
    int len = str.size();
    while(right < len){
        while(visited[str[right]] && (str[left] != str[right]))  //existed repeat char, move to the appear place
            visited[str[left++]] = false;
        if(visited[str[right]]) //move the appear char's next place
            visited[str[left++]] = false;

        visited[str[right]] = true;
        int cur_len = right - left + 1;

        if(max_len < cur_len){
            max_len = cur_len;
            longest_left = left;
            longest_right = right;
        }
        right++;
    }

    string substr = str.substr(longest_left, longest_right - longest_left + 1);
    cout <<"--"<< substr << "---" << longest_right << " -- " << longest_left << endl;
    return longest_right - longest_left + 1;
}

int main(){

    string str = "abcabcdbbef321";

    int max_len = longest_sub(str);
    cout << "max len " << max_len << endl;
    return 0;
}
