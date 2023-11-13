#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarPlaca(char *placa) {
    int i, formatoValido = 0;
    int comprimento = strlen(placa);

    if (comprimento == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2])) {
        formatoValido = 1;
    }
    
    else if (comprimento == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
               isdigit(placa[3]) && isalpha(placa[4]) && isdigit(placa[5]) && isdigit(placa[6])) {
        formatoValido = 1;
    }

    return formatoValido;
}

int validarDia(char *dia) {
    char diasValidos[7][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    int i, diaValido = 0;

    for (i = 0; i < 7; i++) {
        if (strcmp(dia, diasValidos[i]) == 0) {
            diaValido = 1;
            break;
        }
    }

    return diaValido;
}

int imprimirResultado(char *placa, char *dia, int placaValida, int diaValido, int podeCircular) {
    if (!placaValida) {
        printf("Placa invalida\n");
    }

    if (!diaValido) {
        printf("Dia da semana invalido\n");
    }

    if (podeCircular && (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0)) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (podeCircular) {
        printf("%s pode circular %s\n", placa, dia);
    } else if (placaValida && diaValido) {
        printf("%s nao pode circular %s\n", placa, dia);
    }
}

int verificarRodizio(char *placa, char *dia) {
    int terminacao = placa[strlen(placa) - 1] - '0';
    int diaInvalido = 1;

    if (strcmp(dia, "SEGUNDA-FEIRA") == 0 && (terminacao == 0 || terminacao == 1)) {
        diaInvalido = 0;
    } else if (strcmp(dia, "TERCA-FEIRA") == 0 && (terminacao == 2 || terminacao == 3)) {
        diaInvalido = 0;
    } else if (strcmp(dia, "QUARTA-FEIRA") == 0 && (terminacao == 4 || terminacao == 5)) {
        diaInvalido = 0;
    } else if (strcmp(dia, "QUINTA-FEIRA") == 0 && (terminacao == 6 || terminacao == 7)) {
        diaInvalido = 0;
    } else if (strcmp(dia, "SEXTA-FEIRA") == 0 && (terminacao == 8 || terminacao == 9)) {
        diaInvalido = 0;
    } else if (strcmp(dia, "SABADO") == 0 || strcmp(dia, "DOMINGO") == 0) {
        diaInvalido = 0;
    }

    return diaInvalido;
}

int main() {
    char placa[20];
    char dia[15];

    printf("Digite a placa do veiculo: ");
    scanf("%s", placa);

    printf("Digite o dia da semana: ");
    scanf("%s", dia);

    int placaValida = validarPlaca(placa);
    int diaValido = validarDia(dia);

    if (!placaValida || !diaValido) {
        imprimirResultado(placa, dia, placaValida, diaValido, 0);
        return 0;
    }

    int podeCircular = !verificarRodizio(placa, dia);
    imprimirResultado(placa, dia, placaValida, diaValido, podeCircular);

    return 0;
}
