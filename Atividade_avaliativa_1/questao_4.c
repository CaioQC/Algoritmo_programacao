#include <stdio.h>

int main(){
    
    char nivel;
    float salario;
    float aumento;

    scanf(" %c", &nivel);
    
    scanf("%f", &salario);

    if (nivel == 'a') {
        aumento = salario * 0.05;
    } else if (nivel == 'b') {
        aumento = salario * 0.07;
    } else if (nivel == 'c') {
        aumento = salario * 0.08;

    float novo_salario = salario + aumento;

    printf("R$ %.2f\n", novo_salario);

    return 0;
}
