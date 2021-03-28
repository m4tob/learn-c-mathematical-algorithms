#include <stdio.h>
#include <math.h>

float f(float x) {
    // f(x) = x³ - 9x + 3
    return (x*x*x) - (9.0*x) + 3.0;
}

void main(int argc, char *argv[]) {
    float x0, xn, xn1, erro;
    float fxn;              // Variável para armazenar f(xn)
    int maxIteracoes = 100; // o número máximo de iterações que o algoritmo vai executar antes de parar
    int iteracao = 1;       // indica qual a iteracao atual

    printf("Informe o valor x0: ");
    scanf("%f", &x0);
    printf("Informe o valor x1: ");
    scanf("%f", &xn);
    printf("Informe o valor máximo para o erro absoluto: ");
    scanf("%f", &erro);

    printf("   n  |    x(n-1)   |     x(n)    |     f(x0)    |     f(xn)\n");
    printf(" ----------------------------------------------------------------\n");

    do {
        fxn = f(xn);

        printf("%4d  | %2.9f | %2.9f | %2.9f | %2.9f  \n", iteracao, x0, xn, f(x0), fxn);

        xn1 = xn - fxn * ((xn - x0) / (fxn - f(x0)));

        x0 = xn;
        xn = xn1;

        iteracao++;
    } while (iteracao <= maxIteracoes && fabs(fxn) >= erro);
}