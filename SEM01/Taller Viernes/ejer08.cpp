#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    float a,b,c,p,S;
    a = 3;
    b = 7;
    c = 5;
    p = (a+b+c)/2;
    S = sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<"lado1 = "<<a<<endl;
    cout<<"lado2 = "<<b<<endl;
    cout<<"lado3 = "<<c<<endl;
    cout<<"semi perimetro = "<<p<<endl;
    cout<<"area = "<<S<<endl;
    return 0;
}