#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    int prioridade;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
} FilaPrioridade;

void inicializarFila(FilaPrioridade *fila) {
    fila->inicio = NULL;
}

No* criarNo(int valor, int prioridade) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prioridade = prioridade;
    novoNo->proximo = NULL;
    return novoNo;
}

void enfileirar(FilaPrioridade *fila, int valor, int prioridade) {
    No* novoNo = criarNo(valor, prioridade);

    if (fila->inicio == NULL || prioridade < fila->inicio->prioridade) {
        novoNo->proximo = fila->inicio;
        fila->inicio = novoNo;
    } else {
        No *atual = fila->inicio;
        while (atual->proximo != NULL && atual->proximo->prioridade <= prioridade) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

int desenfileirar(FilaPrioridade *fila) {
    if (fila->inicio == NULL) {
        printf("fila vazia.\n");
        return -1;
    }
    No* noRemovido = fila->inicio;
    int valorRemovido = noRemovido->valor;
    fila->inicio = noRemovido->proximo;
    free(noRemovido);
    return valorRemovido;
}

void imprimirFila(FilaPrioridade *fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("valor: %d | prioridade: %d\n", atual->valor, atual->prioridade);
        atual = atual->proximo;
    }
}

int main() {
    FilaPrioridade fila;
    inicializarFila(&fila);

    enfileirar(&fila, 30, 2);
    enfileirar(&fila, 10, 1);
    enfileirar(&fila, 20, 3);

    printf("fila de prioridade:\n");
    imprimirFila(&fila);

    printf("\nremovendo elemento de maior prioridade: %d\n", desenfileirar(&fila));
    printf("fila apos remocao:\n");
    imprimirFila(&fila);

    return 0;
}
