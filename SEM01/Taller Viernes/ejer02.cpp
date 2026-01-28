#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int b,h,A,P,d;
    b = 8;
    h = 6;
    A = b*h;
    P = 2*(b+h);
    d = sqrt(b*b + h*h);
    cout<<"base = "<<b<<endl;
    cout<<"altura = "<<h<<endl;
    cout<<"area = "<<A<<endl;
    cout<<"perimetro = "<<P<<endl;
    cout<<"diagonal = "<<d<<endl;
    return 0;
}