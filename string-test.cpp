#include<iostream>
#include "string.h"
using namespace std;

int main(){
    String s1("hello world");
    String s2("hello");


    String* p = new String("world");
    delete p;
    cout<<s1;
    return 0;
}