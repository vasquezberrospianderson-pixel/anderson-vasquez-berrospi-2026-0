<<<<<<< HEAD
#include <stdio.h>
int main() {
    float B, b, h, A;
    printf("Ingrese la base mayor: ");
    scanf("%f", &B);
    printf("Ingrese la base menor: ");
    scanf("%f", &b);
    printf("Ingrese la altura: ");
    scanf("%f", &h);
    A = ((B + b) * h) / 2;
    printf("Base mayor = %.2f\n", B);
    printf("Base menor = %.2f\n", b);
    printf("Altura = %.2f\n", h);
    printf("Area = %.2f\n", A);
    return 0;
}
=======
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int B,b,h,A;
    B = 10;
    b = 6;
    h = 5;
    A = ((B+b)*h)/2;
    cout<<"base mayor = "<<B<<endl;
    cout<<"base menor = "<<b<<endl;
    cout<<"altura = "<<h<<endl;
    cout<<"area = "<<A<<endl;
    return 0;
}
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
