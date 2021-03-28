#include <stdio.h>
#include <math.h>

float f(float x) {
    // f(x) = x³ - 9x + 3
    return (x*x*x) - (9.0*x) + 3.0;
}

void main(int argc, char *argv[]) {
    float a, b, c, erro;
    int maxIteracoes = 100; // o número máximo de iterações que o algoritmo vai executar antes de parar
    int iteracao = 1;       // indica qual a iteracao atual

    printf("Informe o valor a do intervalo [a,b]: ");
    scanf("%f", &a);
    printf("Informe o valor b do intervalo [a,b]: ");
    scanf("%f", &b);
    printf("Informe o valor máximo para o erro absoluto: ");
    scanf("%f", &erro);

    printf("   n  |      a      |      b      |      x      |     f(a)    |     f(x)\n");
    printf(" ----------------------------------------------------------------------------\n");

    do {
        c = (a + b) / 2.0; // Ponto médio entr 'a' e 'b'

        printf("%4d  | %2.9f | %2.9f | %2.9f | %2.9f | %2.9f \n", iteracao, a, b, c, f(a), f(c));

        if ((f(a) * f(c)) > 0.0) // f(a) e f(c) possuem o mesmo sinal, logo a raiz está à direita de c
            a = c;
        else if ((f(a) * f(c)) < 0.0) // f(a) e f(c) possuem sinais opostos, logo a raiz está à esquerda de c
            b = c;

        iteracao++;
    } while (iteracao <= maxIteracoes && fabs(f(c)) >= erro); // Irá esecutar até que o erro absoluto seja maior que a variável erro
}