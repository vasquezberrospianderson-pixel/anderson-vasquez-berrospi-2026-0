#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int D,d,A,I,P;
    D = 8;
    d = 6;
    A = (D*d)/2;
    I = sqrt(D/2*D/2 + d/2*d/2);
    P = 4*I;
    cout<<"diagonal mayor = "<<D<<endl;
    cout<<"diagonal menor = "<<d<<endl;
    cout<<"area = "<<A<<endl;
    cout<<"lado = "<<I<<endl;
    cout<<"perimetro = "<<P<<endl;
    return 0;
}