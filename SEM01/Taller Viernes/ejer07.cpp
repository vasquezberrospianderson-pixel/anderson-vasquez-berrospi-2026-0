#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a,b,c,r,p,S;
    a = 9;
    b = 12;
    c = 15;
    r = 6;
    p = (a+b+c)/2;
    S = r*p;
    cout<<"lado1 = "<<a<<endl;
    cout<<"lado2 = "<<b<<endl;
    cout<<"lado3 = "<<c<<endl;
    cout<<"radio = "<<r<<endl;
    cout<<"semi perimetro = "<<p<<endl;
    cout<<"area = "<<S<<endl;
    return 0;
}