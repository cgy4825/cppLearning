#include<iostream>
#include "fraction.h"
using namespace std;

int main(){
    Fraction f(3,5);
    double d = 4 + f;
    cout<<d<<endl;
    return 0;
}