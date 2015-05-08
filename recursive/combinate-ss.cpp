/*************************************************************************
    > File Name: sum.cpp
    > Author: gchch
    > Mail: 1306890576@qq.com
    > Created Time: Tue 28 Apr 2015 01:59:50 PM CST
 ************************************************************************/
#include <list>
#include<iostream>
using namespace std;

list<int>list1;

void find_num(int sum,int n)
{
    if((n < 0) || (sum <0))
        return;

    if(sum == 0){
        for(list<int>::iterator iter=list1.begin();iter!=list1.end();iter++)
                    cout<<*iter<<"+";
        cout<<endl;
          return;
     }

    for(int i = n; i >= 0; i--){
        list1.push_front(i);
        find_num(sum-i, i - 1);     //放n
        list1.pop_front();
        // find_num(sum,n-1);       //不放n
    }

}

int main()
{
    int sum,n;
    cout<<"请输入和为："<<endl;
    cin>>sum;
    cout<<"请输入从1....n数列中取值的n"<<endl;
    cin>>n;
    cout<<"可能的序列如下："<<endl;
    find_num(sum,n);
    return 0;
}
