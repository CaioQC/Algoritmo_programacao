#include <stdio.h>
#include <math.h>

int main() {
    int meses;
    double aporte, taxa, montante;

    printf("Digite o número de meses, o aporte mensal e a taxa de retorno mensal: ");
    scanf("%d %lf %lf", &meses, &aporte, &taxa);

    for (int i = 1; i <= meses; i++) {
        montante = (aporte * (1 + taxa)) *((pow(1 + taxa, i) - 1) / taxa);
        printf("Montante ao fim do mês %d: R$ %.2lf\n", i, montante);
    }

    return 0;
}