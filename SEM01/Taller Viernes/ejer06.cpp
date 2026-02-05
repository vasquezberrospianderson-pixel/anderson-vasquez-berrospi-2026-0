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
