#include <stdio.h>
int main() {
    int a, b, c, r, p, S;
    printf("Ingrese el lado 1: ");
    scanf("%d", &a);
    printf("Ingrese el lado 2: ");
    scanf("%d", &b);
    printf("Ingrese el lado 3: ");
    scanf("%d", &c);
    printf("Ingrese el radio: ");
    scanf("%d", &r);
    p = (a + b + c) / 2;
    S = r * p;
    printf("lado1 = %d\n", a);
    printf("lado2 = %d\n", b);
    printf("lado3 = %d\n", c);
    printf("radio = %d\n", r);
    printf("semi perimetro = %d\n", p);
    printf("area = %d\n", S);
    return 0;
}
