#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, p, S;
    printf("Ingrese el lado 1: ");
    scanf("%f", &a);
    printf("Ingrese el lado 2: ");
    scanf("%f", &b);
    printf("Ingrese el lado 3: ");
    scanf("%f", &c);
    p = (a + b + c) / 2;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("lado1 = %.2f\n", a);
    printf("lado2 = %.2f\n", b);
    printf("lado3 = %.2f\n", c);
    printf("semi perimetro = %.2f\n", p);
    printf("area = %.2f\n", S);
    return 0;
}
