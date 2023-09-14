#include <stdio.h>

int main(){
    
    int senha_certa, senha_inserida;

    scanf("%d", &senha_certa);

    while (1) {
        scanf("%d", &senha_inserida);

        if (senha_inserida == senha_certa) {
            printf("senha valida!\n");
            break;
        } else {
            printf("senha invalida!\n");
        }
    }

    return 0;
}
