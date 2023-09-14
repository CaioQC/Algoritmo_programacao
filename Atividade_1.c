#include <stdio.h>

int main() {
    int ano;

    scanf("%d", &ano);

    if ((ano >= 1896 && ano <= 2022) && (ano % 4 == 0) && (ano != 1916) && (ano != 1940) && (ano != 1944)) {
        printf("Os Jogos Olímpicos de Verão ocorreram no ano de %d.\n", ano);
    } 
    
    else if (ano >= 1930 && (ano - 1930) % 4 == 0 && (ano != 1942) && (ano != 1946)) {
        printf("A Copa do Mundo de Futebol ocorreu no ano de %d.\n", ano);
    } 

    else {
        printf("Não houve Jogos Olímpicos de Verão ou Copa do Mundo no ano de %d.\n", ano);
    }

    return 0;
}
