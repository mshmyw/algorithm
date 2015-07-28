//file name : virtual-destruct.cpp
//created at: Sat Jul 18 20:29:19 2015
//author:  root

#include <iostream>
using namespace std;

class Base {
public:
    Base() : bValue(1) {}
    virtual ~Base() { cout << "Base destructor" << endl; }
    // ~Base() { cout << "Base destructor" << endl; }
    virtual void print() {
        cout << "print : base" << endl;
    }
private:
    int bValue;
};

class Derived : public Base {
public:
    Derived() : dValue(100) {}
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
    void print() {
        cout << "print : derived" << endl;
    }
private:
    int dValue;
};

int main() {
    Base* p = new Derived();
    p->print();
    delete p;
}
