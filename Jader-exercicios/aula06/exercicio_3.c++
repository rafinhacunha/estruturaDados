#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char c) {
    if (p->topo < MAX - 1)
        p->dados[++(p->topo)] = c;
}

char pop(Pilha *p) {
    if (!vazia(p))
        return p->dados[(p->topo)--];
    return '\0'; 
}

char topo(Pilha *p) {
    if (!vazia(p))
        return p->dados[p->topo];
    return '\0';
}

int ehPar(char aberto, char fechado) {
    return (aberto == '(' && fechado == ')') ||
           (aberto == '[' && fechado == ']') ||
           (aberto == '{' && fechado == '}');
}

int estaBalanceado(const char *expressao) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&pilha, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (vazia(&pilha) || !ehPar(pop(&pilha), c))
                return 0; 
        }
    }
    return vazia(&pilha); 
}

int main() {
    const char *teste1 = "{[()]}";
    const char *teste2 = "{[(])}";
    const char *teste3 = "({})";

    printf("\"%s\": %s\n", teste1, estaBalanceado(teste1) ? "Balanceado" : "Nao balanceado");
    printf("\"%s\": %s\n", teste2, estaBalanceado(teste2) ? "Balanceado" : "Nao balanceado");
    printf("\"%s\": %s\n", teste3, estaBalanceado(teste3) ? "Balanceado" : "Nao balanceado");

    return 0;
}
