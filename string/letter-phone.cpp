#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>

using namespace std;
void letter_inner(string digits, vector<string> mapping, string &tmp, vector<string> &res){
    if(digits.size() == tmp.size()){
        res.push_back(tmp);
        return;
    }
    int i = digits[tmp.size()] - '0';
    for(int j = 0; j < mapping[i].size(); j++){
        tmp.push_back(mapping[i][j]);
        letter_inner(digits, mapping, tmp, res);
        tmp.erase(tmp.size() - 1);
    }
    return;
}

vector<string> letterCombinations(string digits) {
     vector<string> res;
     char *str[8] =  {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
     vector<string> mapping(str, str + 8);
     string tmp = "";
     letter_inner(digits, mapping, tmp, res);
     for(int i = 0; i < res.size(); i++)
         cout << res[i] << endl;
     return res;
 }

int main(void){
    string str = "121";
    letterCombinations(str);

    return 0;
}
