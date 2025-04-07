#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int tamanho;
} Lista;

void inicializa(Lista *l) {
    l->tamanho = 0;
}

void insere(Lista *l, int valor) {
    if (l->tamanho >= MAX) {
        printf("lista cheia!\n");
        return;
    }
    int i = l->tamanho - 1;
    while (i >= 0 && l->arr[i] > valor) {
        l->arr[i + 1] = l->arr[i];
        i--;
    }
    l->arr[i + 1] = valor;
    l->tamanho++;
}

void exibe(Lista *l) {
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->arr[i]);
    }
    printf("\n");
}

int main() {
    Lista l;
    inicializa(&l);
    
    int n, valor;
    printf("digite a quantidade de elementos a serem inseridos: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("digite um valor: ");
        scanf("%d", &valor);
        insere(&l, valor);
        exibe(&l);
    }

    return 0;
}
