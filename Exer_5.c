#include <stdio.h>

typedef struct {
    float real;
    float imag;
} Complexo;

void Atribui(Complexo *c, float r, float i) {
    c->real = r;
    c->imag = i;
}

void Imprime(Complexo c) {
    printf("%.2f + %.2fi\n", c.real, c.imag);
}

void Copia(Complexo *destino, Complexo origem) {
    destino->real = origem.real;
    destino->imag = origem.imag;
}

Complexo Soma(Complexo c1, Complexo c2) {
    Complexo res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

int EhReal(Complexo c) {
    if (c.imag == 0) return 1;
    return 0;
}

int main(void) {
    Complexo c1, c2, c3;
    Atribui(&c1, 3.0, 4.0);
    Atribui(&c2, 1.0, 2.0);
    Imprime(c1);
    c3 = Soma(c1, c2);
    Imprime(c3);
    return 0;
}