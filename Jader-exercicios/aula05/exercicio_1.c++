#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int valor;
    struct Elemento *proximo;
} Elemento;

Elemento* criarElemento(int valor) {
    Elemento *novoElem = (Elemento*) malloc(sizeof(Elemento));
    if (novoElem != NULL) {
        novoElem->valor = valor;
        novoElem->proximo = NULL;
    }
    return novoElem;
}

void adicionarElemento(Elemento **inicio, int valor) {
    Elemento *novoElem = criarElemento(valor);
    if (*inicio == NULL) {
        *inicio = novoElem;
    } else {
        Elemento *atual = *inicio;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novoElem;
    }
}

void mostrarLista(Elemento *inicio) {
    while (inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

Elemento* inverterLista(Elemento *inicio) {
    Elemento *anterior = NULL, *atual = inicio, *seguinte = NULL;
    while (atual != NULL) {
        seguinte = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = seguinte;
    }
    return anterior;
}

int main() {
    Elemento *inicio = NULL;
    
    adicionarElemento(&inicio, 1);
    adicionarElemento(&inicio, 2);
    adicionarElemento(&inicio, 3);
    adicionarElemento(&inicio, 4);
    
    printf("lista original: ");
    mostrarLista(inicio);
    
    inicio = inverterLista(inicio);
    
    printf("lista invertida: ");
    mostrarLista(inicio);
    
    return 0;
}
