#include <stdio.h>
int main() {
    float a, b, c, h, A, P;
    printf("Ingrese el lado 1: ");
    scanf("%f", &a);
    printf("Ingrese el lado 2: ");
    scanf("%f", &c);
    printf("Ingrese la base: ");
    scanf("%f", &b);
    printf("Ingrese la altura: ");
    scanf("%f", &h);
    A = (b * h) / 2;
    P = a + b + c;
    printf("Lado 1 = %.2f\n", a);
    printf("Lado 2 = %.2f\n", c);
    printf("Base = %.2f\n", b);
    printf("Altura = %.2f\n", h);
    printf("Area = %.2f\n", A);
    printf("Perimetro = %.2f\n", P);
    return 0;
}
