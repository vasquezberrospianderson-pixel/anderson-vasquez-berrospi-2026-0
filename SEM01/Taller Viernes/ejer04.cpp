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
