<<<<<<< HEAD
#include <stdio.h>
#include <math.h>
int main() {
    float lado, area, perimetro, diagonal;
    printf("Ingrese el lado del cuadrado: ");
    scanf("%f", &lado);
    area = lado * lado;
    perimetro = 4 * lado;
    diagonal = lado * sqrt(2);
    printf("Lado: %.2f\n", lado);
    printf("Area: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);
    printf("Diagonal: %.2f\n", diagonal);
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
>>>>>>> 6e4683b39acd7485c8f5e774ff1d2d2691194926
    return 0;
}