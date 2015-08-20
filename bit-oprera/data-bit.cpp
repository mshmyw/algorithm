//file name : data-bit.cpp
//created at: Sat Jul 25 19:45:36 2015
//author:  root

#include<iostream>
#include<vector>
#include<string>
#include<bitset>

using namespace std;

void print(vector<int> res){
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << "  ";
    cout << endl;

    return;
}


int main(void){

    int n;
    const int max = (1 << 20);
    cout << " max " << max << endl;
    bitset<max + 1> bit; //default the all of bits is 0
    bit.set(1000, 1);
    bit.set(10000, 1);

    for(int i = 0; i < max + 1; i++)
        if(bit[i] == 1)
            cout << "bit " << i << endl;

    return 0;
}
