//file name : reference-to-const.cpp
//created at: Fri Aug 14 08:52:50 2015
//author:  root

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Tr{
public:
    Tr(int n):i(n){}

    void set_i(int n){i = n;}
    int get_i(){return i;}
private:
    int i;
};

void sqr_it1(Tr ob){
    ob.set_i(ob.get_i() * ob.get_i());
    cout<<"in sqrt_it1, i = "<<ob.get_i()<<endl;
}

void sqr_it2(Tr *ob){
    ob->set_i(ob->get_i() * ob->get_i());
    cout<<"in sqrt_it2, i ="<<ob->get_i()<<endl;
}

void sqr_it3(Tr &ob){
    ob.set_i(ob.get_i() * ob.get_i());
    cout<<"in sqrt_it2, i ="<<ob.get_i()<<endl;
}

int main(void){

    Tr obj(10);
    cout<<"before sqr_it, i = "<<obj.get_i()<<endl;
    sqr_it1(obj);
    cout<<"after sqr_it1, i = "<<obj.get_i()<<endl;
    sqr_it2(&obj);
    cout<<"after sqr_it2, i = "<<obj.get_i()<<endl;
    sqr_it3(obj);
    cout<<"after sqr_it2, i = "<<obj.get_i()<<endl;

    return 0;
}
