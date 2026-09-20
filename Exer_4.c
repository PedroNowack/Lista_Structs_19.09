/*As funções VerificaNum e ConsultaSaldo devem estar no TAD Conta Bancária porque
elas leem dados diretos de uma única conta. O TAD Banco apenas armazena a lista de contas.
*/
#include <stdio.h>

typedef struct {
    int numero;
    float saldo;
} ContaBancaria;

typedef struct {
    ContaBancaria vet[100];
    int quantidade;
} Contas;

int VerificaNum(ContaBancaria cont, int num) {
    if (cont.numero == num) return 1;
    return 0;
}

float ConsultaSaldo(ContaBancaria conta) {
    return conta.saldo;
}

void InicializaContas(Contas *cnt) {
    cnt->quantidade = 0;
}

void CriarNovasContas(Contas *cnt, int n) {
    int i;
    for (i = 0; i < n; i++) {
        cnt->vet[cnt->quantidade].numero = cnt->quantidade + 1;
        scanf("%f", &cnt->vet[cnt->quantidade].saldo);
        cnt->quantidade++;
    }
}

void ImprimirContas(Contas *cnt) {
    int i;
    for (i = 0; i < cnt->quantidade; i++) {
        printf("Conta: %d | Saldo: %.2f\n", cnt->vet[i].numero, ConsultaSaldo(cnt->vet[i]));
    }
}

void ZerarSaldoConta(Contas *cnt, int num) {
    int i;
    for (i = 0; i < cnt->quantidade; i++) {
        if (VerificaNum(cnt->vet[i], num) == 1) {
            cnt->vet[i].saldo = 0;
            return;
        }
    }
}

int main(void) {
    Contas banco;
    InicializaContas(&banco);
    CriarNovasContas(&banco, 2);
    ImprimirContas(&banco);
    ZerarSaldoConta(&banco, 1);
    ImprimirContas(&banco);
    return 0;
}