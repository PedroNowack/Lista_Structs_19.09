#include <stdio.h>

typedef struct {
    char nome[100];
    int matricula;
    float nota1;
    float nota2;
} Aluno;

int main(void) {
    Aluno alunos[3];
    int i;

    for (i = 0; i < 3; i++) {
        scanf("%s %d %f %f", alunos[i].nome, &alunos[i].matricula, &alunos[i].nota1, &alunos[i].nota2);
    }

    printf("\nMatricula  Nome         Media\n");
    for (i = 0; i < 3; i++) {
        float media = (alunos[i].nota1 + alunos[i].nota2) / 2.0f;
        printf("%d %s %.2f\n", alunos[i].matricula, alunos[i].nome, media);
    }

    return 0;
}