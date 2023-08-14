#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1, nota2, nota3, media;
    char turno;

    printf("Digite turno:\n");
    scanf("%c", &turno);

    printf("Digite notas:\n\n");
    scanf("%f", &nota1);

    scanf("%f", &nota2);
    
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3)/3;
    printf("MEDIA: %f\n\n", media);
    printf("Aluno do turno %c\n\n", turno);

    if(turno == 'N')
    {
        printf("Noturno\n\n");
    }
    else if(turno == 'M')
    {
        printf("Matutino\n\n");
    }

    else
    {
        printf("Não existe\n\n");
    }

    if (media > 8)
    {
        printf("Sua nota é: 10 \n\n");
    }

    else if (media > 7 && media <8){
        media++;
        printf("Sua nota é: %f\n\n", media);
    }

    if (media < 7)
    {
        printf("Reprovado\n\n");
    }

    else
    {
        printf("Aprovado\n\n");
    }

return 0;
}
