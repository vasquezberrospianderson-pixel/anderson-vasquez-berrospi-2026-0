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

