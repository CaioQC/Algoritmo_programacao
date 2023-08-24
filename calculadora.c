#include <stdio.h>

int main(){

    long long int numero1, numero2;
    long long int resultado;
    char operacao;

    printf("Insira uma operacao:");
    scanf("%c", &operacao);

    printf("Insira dois números:\n");
    scanf("%lld", &numero1);
    scanf("%lld", &numero2);

    if(operacao == '+'){
        resultado = numero1 + numero2;
        printf("Resultado: ", resultado);
        printf("%lld\n", resultado);
    }
    
    else if(operacao == '-'){
        resultado = numero1 - numero2;
        printf("Resultado: ", resultado);
        printf("%lld\n", resultado);
    }

    else if(operacao == '/'){
        resultado = numero1/numero2;
        printf("Resultado: ", resultado);
        printf("%lld\n", resultado);
    }

    else if(operacao == '%'){
        resultado = numero1 % numero2;
        printf("Resultado: ", resultado);
        printf("%lld\n", resultado);    
    }

    else if(operacao == '*'){
        resultado = numero1 * numero2;
        printf("Resultado: ", resultado);
        printf("%lld\n", resultado);
    }

    else if(operacao == '>' && numero1 > numero2){
        printf("%lld maior que %lld\n", numero1, numero2);
    }

    else if(operacao == '>' && numero1 < numero2){
        printf("%lld menor que %lld\n", numero1, numero2);
    }

    else if(operacao == '>' && numero1 == numero2){
        printf("%lld é igual %lld\n", numero1, numero2);
    }

    else{
        printf("OPERACAO INVALIDA!");
    }


    return 0;

}