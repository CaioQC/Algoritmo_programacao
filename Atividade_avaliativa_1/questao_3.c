#include <stdio.h>

int main(){
    
    int senha_certa, senha_inserida;

    scanf("%d", &senha_certa);

    while (senha_inserida != senha_certa) {
        scanf("%d", &senha_inserida);

        if (senha_inserida == senha_certa) {
            printf("senha valida!\n");

        } else {
            printf("senha invalida!\n");
        }
    }

    return 0;
}
