#include <stdio.h>

typedef struct {
    char nome[100];
    char genero[50];
    int num_integrantes;
    int ranking;
} Banda;

void buscar_banda(Banda *bandas, int pos) {
    int i;
    for (i = 0; i < 5; i++) {
        if ((bandas + i)->ranking == pos) {
            printf("\nNome: %s\n", (bandas + i)->nome);
            printf("Genero: %s\n", (bandas + i)->genero);
            printf("Integrantes: %d\n", (bandas + i)->num_integrantes);
            printf("Ranking: %d\n", (bandas + i)->ranking);
            return;
        }
    }
}

int main(void) {
    Banda bandas[5];
    int i, pos;

    for (i = 0; i < 5; i++) {
        Banda *p = &bandas[i];
        scanf(" %[^\n]", p->nome);
        scanf(" %[^\n]", p->genero);
        scanf("%d", &p->num_integrantes);
        scanf("%d", &p->ranking);
    }

    for (i = 0; i < 5; i++) {
        Banda *p = &bandas[i];
        printf("\nBanda: %s | Genero: %s | Integrantes: %d | Ranking: %d\n", p->nome, p->genero, p->num_integrantes, p->ranking);
    }

    scanf("%d", &pos);
    buscar_banda(bandas, pos);

    return 0;
}