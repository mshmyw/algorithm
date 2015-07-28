//file name : two-sum.cpp
//created at: Mon Jun 29 20:33:21 2015
//author:  root

#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

void two_sum(vector<int> num, int item){
    if(num.size() == 0)
        return;
    int first, second;
    first = second = -1;

    map<int, int> hash;

    for(int i = 0; i < num.size(); i++){
        map<int, int>::iterator iter = hash.find(item - num[i]);
        if(iter == hash.end())
            hash[num[i]] = i;
        else{
            first = iter->second;
            second = i;
            break;
        }
    }

    cout << "first  " << first << "\nsecond " << second << endl;

    return;
}

int main(void){

    int a[] = {2, 3, 5, 7, 4, 6, 15};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> num(a, a + n);
    int item  = 22;

    two_sum(num, item);
    return 0;
}
