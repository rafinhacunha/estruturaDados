#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, int valor) {
    if (p->topo < MAX - 1)
        p->dados[++(p->topo)] = valor;
}

int pop(Pilha *p) {
    if (!vazia(p))
        return p->dados[(p->topo)--];
    return -1; 
}

void inserirNoFundo(Pilha *p, int valor) {
    if (vazia(p)) {
        push(p, valor);
    } else {
        int temp = pop(p);
        inserirNoFundo(p, valor);
        push(p, temp);
    }
}

void inverterPilha(Pilha *p) {
    if (!vazia(p)) {
        int temp = pop(p);
        inverterPilha(p);
        inserirNoFundo(p, temp);
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);

    printf("pilha original (topo -> base): ");
    for (int i = pilha.topo; i >= 0; i--)
        printf("%d ", pilha.dados[i]);
    printf("\n");

    inverterPilha(&pilha);

    printf("pilha invertida (topo -> base): ");
    for (int i = pilha.topo; i >= 0; i--)
        printf("%d ", pilha.dados[i]);
    printf("\n");

    return 0;
}
