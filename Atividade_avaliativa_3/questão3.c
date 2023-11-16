#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarPlaca(char *placa) {
    int i, formatoValido = 0;
    int comprimento = strlen(placa);

    if (comprimento == 8 && placa[3] == '-' && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2])) {
        formatoValido = 1;
    } else if (comprimento == 7 && isalpha(placa[0]) && isalpha(placa[1]) && isalpha(placa[2]) &&
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

    if (podeCircular && (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0)) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (podeCircular) {
        printf("%s pode circular %s\n", placa, dia);
    } else if (placaValida && diaValido) {
        printf("%s nao pode circular %s\n", placa, dia);
    }

    return 0;
}

int verificarRodizio(char *placa, char *dia) {
    int terminacao = placa[strlen(placa) - 1] - '0';
    int diaInvalido = 0;

    for (int i = 0; dia[i]; i++) {
        dia[i] = tolower(dia[i]);
    }

    if (strcmp(dia, "segunda-feira") == 0 && (terminacao == 0 || terminacao == 1)) {
        diaInvalido = 1;
    } else if (strcmp(dia, "terca-feira") == 0 && (terminacao == 2 || terminacao == 3)) {
        diaInvalido = 1;
    } else if (strcmp(dia, "quarta-feira") == 0 && (terminacao == 4 || terminacao == 5)) {
        diaInvalido = 1;
    } else if (strcmp(dia, "quinta-feira") == 0 && (terminacao == 6 || terminacao == 7)) {
        diaInvalido = 1;
    } else if (strcmp(dia, "sexta-feira") == 0 && (terminacao == 8 || terminacao == 9)) {
        diaInvalido = 1;
    } else if (strcmp(dia, "sabado") == 0 || strcmp(dia, "domingo") == 0) {
        diaInvalido = 0;
    }

    return diaInvalido;
}

int main() {
    char placa[20];
    char dia[15];

    scanf("%s", placa);
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
