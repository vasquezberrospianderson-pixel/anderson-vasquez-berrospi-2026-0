<<<<<<< HEAD
#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, p, S;
    printf("Ingrese el lado 1: ");
    scanf("%f", &a);
    printf("Ingrese el lado 2: ");
    scanf("%f", &b);
    printf("Ingrese el lado 3: ");
    scanf("%f", &c);
    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("lado1 = %.2f\n", a);
    printf("lado2 = %.2f\n", b);
    printf("lado3 = %.2f\n", c);
    printf("semi perimetro = %.2f\n", p);
    printf("area = %.2f\n", S);
    return 0;
}
=======
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
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
