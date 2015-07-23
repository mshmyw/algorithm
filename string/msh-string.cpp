//file name : msh-string.cpp
//created at: Thu Jul 23 11:05:34 2015
//author:  root

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

class Mstring{
public:
    Mstring(const char *str = NULL);
    Mstring(const Mstring &other);
    ~Mstring();
    Mstring & operator = (const Mstring &other);
private:
    char *m_data;
};

Mstring::Mstring(const char *str){
    if(str == NULL){
        m_data = new char[1];
        if(m_data != NULL)
            *m_data = '\0';
    }else{
        int length = strlen(str);
        m_data = new char[length + 1];
        if(m_data != NULL)
            strcpy(m_data, str);
    }
}

Mstring::Mstring(const Mstring &other){
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    if(m_data != NULL)
        strcpy(m_data, other.m_data);
}


Mstring & Mstring::operator = (const Mstring &other){
    if(this == &other)
        return *this;

    if(m_data != NULL){
        delete [] m_data;
        m_data = NULL;
    }

    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    if(m_data != NULL)
        strcpy(m_data, other. m_data);

    return *this;
}

Mstring::~Mstring(){
    delete [] m_data;
}

int main(void){
    Mstring str1;
    Mstring str2("abc");

    return 0;
}
