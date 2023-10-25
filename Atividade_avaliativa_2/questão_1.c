#include <stdio.h>

int main() {
    int valores[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("%d", valores[i]);
        if (i < 9) {
            printf(" ");
        }
    }
    
    printf("\n");

    int novoConjunto[9];
    int novoTamanho = 0;

    while (novoTamanho < 9) {
        for (int i = 0; i < 9 - novoTamanho; i++) {
            novoConjunto[i] = valores[i] + valores[i + 1];
            valores[i] = novoConjunto[i];
            printf("%d", novoConjunto[i]);
            if (i < 8 - novoTamanho) {
                printf(" ");
            }
        }

        printf("\n");

        novoTamanho++;
    }

    return 0;
}
