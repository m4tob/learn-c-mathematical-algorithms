#include <stdio.h>
#include <math.h>

float f(float x) {
    // f(x) = x³ - 9x + 3
    return (x*x*x) - (9.0*x) + 3.0;
}

float g(float x) {
    // g(x) = (x³-3)/9
    return (pow(x, 3) + 3)/9.0;
}

void main(int argc, char *argv[]) {
    float x, erro;
    float fx;               // Variável para armazenar f(x)
    int maxIteracoes = 100; // o número máximo de iterações que o algoritmo vai executar antes de parar
    int iteracao = 1;       // indica qual a iteracao atual

    printf("Informe o valor x0: ");
    scanf("%f", &x);
    printf("Informe o valor máximo para o erro absoluto: ");
    scanf("%f", &erro);

    printf("   n  |      x      |     f(x)     |     g(x)\n");
    printf(" ------------------------------------------------\n");

    do {
        fx = f(x);

        printf("%4d  | %2.9f | %2.9f | %2.9f \n", iteracao, x, fx, g(x));

        x = g(x);

        iteracao++;
    } while (iteracao <= maxIteracoes && fabs(fx) >= erro);
}