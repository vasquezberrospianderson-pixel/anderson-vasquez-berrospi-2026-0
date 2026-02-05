<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 43a4b5cb5d7eaa716b98044ddcf150a6649a7ca0
#include <stdio.h>
int main() {
    float a, b, c, R, S;
    printf("Ingrese el lado 1: ");
    scanf("%f", &a);
    printf("Ingrese el lado 2: ");
    scanf("%f", &b);
    printf("Ingrese el lado 3: ");
    scanf("%f", &c);
    printf("Ingrese el radio: ");
    scanf("%f", &R);
    S = (a * b * c) / (4 * R);
    printf("Lado 1 = %.2f\n", a);
    printf("Lado 2 = %.2f\n", b);
    printf("Lado 3 = %.2f\n", c);
    printf("Radio = %.2f\n", R);
    printf("Area = %.2f\n", S);
    return 0;
}
<<<<<<< HEAD
=======
=======
#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int a,b,c,R,S;
    a = 9;
    b = 8;
    c = 7;
    R = 6;
    S = (a*b*c)/(4*R);
    cout<<"lado1 = "<<a<<endl;
    cout<<"lado2 = "<<b<<endl;
    cout<<"lado3 = "<<c<<endl;
    cout<<"radio = "<<R<<endl;
    cout<<"area = "<<S<<endl;
    return 0;
}
>>>>>>> 2f0bb2aa90c25e5f2157aa89d3c707ec8bb75c92
>>>>>>> 43a4b5cb5d7eaa716b98044ddcf150a6649a7ca0
