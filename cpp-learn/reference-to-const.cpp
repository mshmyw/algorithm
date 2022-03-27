//file name : reference-to-const.cpp
//created at: Fri Aug 14 08:52:50 2015
//author:  root

#include<iostream>
#include<vector>
#include<string.h>
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


class CPC{
public:
    CPC(){pBuff = NULL; nSize = 0;}
    ~CPC(){delete [] pBuff;}
    CPC(const CPC &theone){//in CPC has pointer, so need to COPY constructer
        nSize = theone.nSize;
        pBuff = new char[nSize];
        memcpy(pBuff, theone.pBuff, nSize);
    }

    void Init(int n){pBuff = new char[n]; nSize = n;}
private:
    char *pBuff;
    int nSize;
};

int main(void){
    CPC theone;
    theone.Init(40);
    CPC theother = theone;

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
