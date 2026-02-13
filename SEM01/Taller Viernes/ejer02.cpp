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
