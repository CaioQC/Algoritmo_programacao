#include <stdio.h>
#include <stdlib.h>

int main(){

    float numero1, numero2, soma, subtracao, divisao, multiplicacao;

    printf("Insira o primeiro valor:\n");
    scanf("%f", &numero1);

    printf("Insira o segundo valor:\n");
    scanf("%f", &numero2);

    soma = numero1 + numero2;
    subtracao = numero1 - numero2;
    divisao = numero1/numero2;
    multiplicacao = numero1 * numero2;

    printf("A soma é: %f\n\n", soma);
    printf("A subtração é: %f\n\n", subtracao);
    printf("A divisão é: %f\n\n", divisao);
    printf("A multiplição é: %f\n\n", multiplicacao);

    return 0;
}