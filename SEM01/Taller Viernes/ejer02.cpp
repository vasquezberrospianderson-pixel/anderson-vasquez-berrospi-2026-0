<<<<<<< HEAD
#include <stdio.h>
#include <math.h>
int main() {
    float b, h, A, P, d;
    printf("Ingrese la base: ");
    scanf("%f", &b);
    printf("Ingrese la altura: ");
    scanf("%f", &h);
    A = b * h;
    P = 2 * (b + h);
    d = sqrt(b * b + h * h);
    printf("Base: %.2f\n", b);
    printf("Altura: %.2f\n", h);
    printf("Area: %.2f\n", A);
    printf("Perimetro: %.2f\n", P);
    printf("Diagonal: %.2f\n", d);
    return 0;
}
=======
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
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
