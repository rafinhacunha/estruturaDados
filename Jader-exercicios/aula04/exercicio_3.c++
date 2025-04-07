#include <stdio.h>
#define MAX 100

typedef struct {
    int dados[MAX];
    int n;
} Lista;

void inicializa(Lista *l) {
    l->n = 0;
}

int insere(Lista *l, int valor) {
    if (l->n >= MAX)
        return 0;
    l->dados[l->n++] = valor;
    return 1;
}

int removeElemento(Lista *l, int valor) {
    int i, pos = -1;
    for (i = 0; i < l->n; i++) {
        if (l->dados[i] == valor) {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return 0;
    for (i = pos; i < l->n - 1; i++)
        l->dados[i] = l->dados[i + 1];
    l->n--;
    return 1;
}

int buscaLinear(Lista *l, int valor) {
    int i;
    for (i = 0; i < l->n; i++) {
        if (l->dados[i] == valor)
            return i;
    }
    return -1;
}

void exibe(Lista *l) {
    int i;
    for (i = 0; i < l->n; i++)
        printf("%d ", l->dados[i]);
    printf("\n");
}

int main() {
    Lista lista;
    inicializa(&lista);
    
    insere(&lista, 10);
    insere(&lista, 20);
    insere(&lista, 30);
    printf("Lista apos insercao: ");
    exibe(&lista);
    
    int pos = buscaLinear(&lista, 20);
    printf("Busca 20: posicao %d\n", pos);
    
    removeElemento(&lista, 20);
    printf("Lista apos remocao de 20: ");
    exibe(&lista);
    
    pos = buscaLinear(&lista, 20);
    printf("Busca 20 apos remocao: posicao %d\n", pos);
    
    return 0;
}
