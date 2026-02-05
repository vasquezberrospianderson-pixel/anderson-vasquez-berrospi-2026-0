<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 43a4b5cb5d7eaa716b98044ddcf150a6649a7ca0
#include <stdio.h>
#include <math.h>
int main() {
    float D, d, A, I, P;
    printf("Ingrese la diagonal mayor: ");
    scanf("%f", &D);
    printf("Ingrese la diagonal menor: ");
    scanf("%f", &d);
    A = (D * d) / 2;
    I = sqrt((D / 2) * (D / 2) + (d / 2) * (d / 2));
    P = 4 * I;
    printf("Diagonal mayor = %.2f\n", D);
    printf("Diagonal menor = %.2f\n", d);
    printf("Area = %.2f\n", A);
    printf("Lado = %.2f\n", I);
    printf("Perimetro = %.2f\n", P);
    return 0;
}
<<<<<<< HEAD
=======
=======
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
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
>>>>>>> 43a4b5cb5d7eaa716b98044ddcf150a6649a7ca0
