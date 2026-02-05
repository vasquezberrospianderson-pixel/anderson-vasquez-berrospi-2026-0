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
