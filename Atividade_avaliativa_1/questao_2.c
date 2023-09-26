#include <stdio.h>

int main(){
    
    int numero;

    scanf("%d", &numero);

    if (numero % 2 == 0) {
        printf("%d eh par\n", numero);
    } else {
        printf("%d eh impar\n", numero);
    }

    int soma = 0;
    int dividendo = numero;
    while (dividendo > 0) {
        soma += dividendo % 10; 
        dividendo = dividendo / 10; 
    }

    printf("A soma dos algarismos de %d eh %d\n", numero, soma);

    return 0;
}
