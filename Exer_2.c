#include <stdio.h>

typedef struct {
    int inscricao;
    char nome[100];
    int classe;
    float horas_normais;
    float horas_extras;
} Ficha;

int main(void) {
    Ficha cadastro[100];
    float salario_ref;
    int n, i;

    scanf("%f", &salario_ref);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &cadastro[i].inscricao);
        scanf(" %[^\n]", cadastro[i].nome);
        scanf("%d", &cadastro[i].classe);
        scanf("%f", &cadastro[i].horas_normais);
        scanf("%f", &cadastro[i].horas_extras);
    }

    for (i = 0; i < n; i++) {
        float valor_hora;
        if (cadastro[i].classe == 1) {
            valor_hora = salario_ref * 1.3f;
        } else {
            valor_hora = salario_ref * 1.9f;
        }

        float v_extras = valor_hora * 1.30f;
        float sal_normais = cadastro[i].horas_normais * valor_hora;
        float sal_extras = cadastro[i].horas_extras * v_extras;
        float bruto = sal_normais + sal_extras;
        float inss = bruto * 0.11f;
        float liquido = bruto - inss;

        printf("NÚMERO DE INSCRIÇÃO: %d NOME: %s\n", cadastro[i].inscricao, cadastro[i].nome);
        printf("SALÁRIO HORAS NORMAIS: %.2f\n", sal_normais);
        printf("SALÁRIO HORAS EXTRAS: %.2f\n", sal_extras);
        printf("DEDUÇÃO INSS: %.2f\n", inss);
        printf("SALÁRIO LÍQUIDO: %.2f\n", liquido);
    }

    return 0;
}