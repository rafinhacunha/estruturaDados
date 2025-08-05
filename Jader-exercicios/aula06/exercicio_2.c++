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

typedef struct {
    Pilha entrada;
    Pilha saida;
} Fila;

void inicializarFila(Fila *f) {
    inicializar(&f->entrada);
    inicializar(&f->saida);
}

void enqueue(Fila *f, int valor) {
    push(&f->entrada, valor);
}

int dequeue(Fila *f) {
    if (vazia(&f->saida)) {
        while (!vazia(&f->entrada)) {
            int temp = pop(&f->entrada);
            push(&f->saida, temp);
        }
    }
    return pop(&f->saida);
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);

    printf("dequeue: %d\n", dequeue(&fila)); 
    enqueue(&fila, 40);
    printf("dequeue: %d\n", dequeue(&fila)); 
    printf("dequeue: %d\n", dequeue(&fila)); 
    printf("dequeue: %d\n", dequeue(&fila)); 

    return 0;
}
