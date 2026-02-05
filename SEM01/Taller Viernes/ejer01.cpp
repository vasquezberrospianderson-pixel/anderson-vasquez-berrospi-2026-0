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
    return 0;
}

=======
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main(){
    float A,P,D,I;
    I=6;
   A=I*I;
   P=4*I;
   D = I * sqrt(2);
   cout<<"lado = "<<I<<endl;
   cout<<"area = "<<A<<endl;
   cout<<"perimetro = "<<P<<endl;
   cout<<"diagonal = "<<D<<endl;
    return 0;
}
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
