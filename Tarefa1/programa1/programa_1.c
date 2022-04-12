#include <stdio.h>

int main()
{
    float b,h;

    printf("\nInforme a base e a altura do triangulo:\n");
    scanf("%f", &b);
    scanf("%f", &h);

    b=b*h/2;

    printf("\nA area do triangulo é: %.2f u.m\n", b);

    return 0;
}
