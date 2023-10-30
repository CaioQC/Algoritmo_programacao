#include <stdio.h>
#include <string.h>

struct Jogador {
    char nome[31];
    char posicao;
    int forca;
};

struct Time {
    char nome[31];
    struct Jogador jogadores[11];
};

int main() {
    struct Time times[2];

    for (int i = 0; i < 2; i++) {
        // Leitura do nome do time com espaço
        scanf(" %30[^\n]", times[i].nome);

        // Leitura dos jogadores
        for (int j = 0; j < 11; j++) {
            char nome[31];
            char posicao;
            int forca;
            scanf(" %30[^;];%c;%d", nome, &posicao, &forca);

            strcpy(times[i].jogadores[j].nome, nome);
            times[i].jogadores[j].posicao = posicao;
            times[i].jogadores[j].forca = forca;
        }
    }

    // Cálculo da força ponderada
    double forcaTimes[2] = {0.0, 0.0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            if (times[i].jogadores[j].posicao == 'G') {
                forcaTimes[i] += 8.0 * times[i].jogadores[j].forca;
            } else if (times[i].jogadores[j].posicao == 'L') {
                forcaTimes[i] += 10.0 * times[i].jogadores[j].forca;
            } else if (times[i].jogadores[j].posicao == 'Z') {
                forcaTimes[i] += 5.0 * times[i].jogadores[j].forca;
            } else if (times[i].jogadores[j].posicao == 'V') {
                forcaTimes[i] += 8.0 * times[i].jogadores[j].forca;
            } else if (times[i].jogadores[j].posicao == 'M') {
                forcaTimes[i] += 11.0 * times[i].jogadores[j].forca;
            } else if (times[i].jogadores[j].posicao == 'A') {
                forcaTimes[i] += 12.0 * times[i].jogadores[j].forca;
            }
        }
        forcaTimes[i] /= 100.0;
    }

    // Saída
    for (int i = 0; i < 2; i++) {
        printf("%s: %.2lf de forca\n", times[i].nome, forcaTimes[i]);
    }

    if (forcaTimes[0] > forcaTimes[1]) {
        printf("%s eh mais forte\n", times[0].nome);
    } else if (forcaTimes[1] > forcaTimes[0]) {
        printf("%s eh mais forte\n", times[1].nome);
    }

    return 0;
}
