#include <stdio.h>
#include <stdlib.h>

typedef struct Processo {
    int id;        
    int tempoRestante; 
    struct Processo *proximo;
} Processo;

Processo* criarProcesso(int id, int tempoExecucao) {
    Processo* novoProcesso = (Processo*)malloc(sizeof(Processo));
    novoProcesso->id = id;
    novoProcesso->tempoRestante = tempoExecucao;
    novoProcesso->proximo = novoProcesso; 
    return novoProcesso;
}

void inserirProcesso(Processo **cabeca, int id, int tempoExecucao) {
    Processo* novoProcesso = criarProcesso(id, tempoExecucao);
    if (*cabeca == NULL) {
        *cabeca = novoProcesso;
        return;
    }
    Processo* aux = *cabeca;
    while (aux->proximo != *cabeca) {
        aux = aux->proximo;
    }
    aux->proximo = novoProcesso;
    novoProcesso->proximo = *cabeca;
}

void removerProcesso(Processo **cabeca, int id) {
    if (*cabeca == NULL)
        return;
    
    Processo *atual = *cabeca, *anterior = NULL;
    
    do {
        if (atual->id == id) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
            } else {
                Processo *ultimo = *cabeca;
                while (ultimo->proximo != *cabeca)
                    ultimo = ultimo->proximo;
                *cabeca = atual->proximo;
                ultimo->proximo = *cabeca;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != *cabeca);
}

void escalonarProcessos(Processo *cabeca, int quantum) {
    if (cabeca == NULL)
        return;
    
    Processo *processoAtual = cabeca;
    printf("iniciando escalonamento round-robin:\n");
    
    while (1) {
        Processo *aux = cabeca;
        int processosPendentes = 0;
        do {
            if (aux->tempoRestante > 0)
                processosPendentes++;
            aux = aux->proximo;
        } while (aux != cabeca);
        
        if (processosPendentes == 0)
            break;
      
        if (processoAtual->tempoRestante > 0) {
            int tempoExecutado = (processoAtual->tempoRestante > quantum) ? quantum : processoAtual->tempoRestante;
            printf("processo %d executando por %d unidades de tempo.\n", processoAtual->id, tempoExecutado);
            processoAtual->tempoRestante -= tempoExecutado;
        }
        // avanca para o proximo processo
        processoAtual = processoAtual->proximo;
    }
    
    printf("escalonamento concluido. todos os processos finalizaram sua execucao.\n");
}

void imprimirProcessos(Processo *cabeca) {
    if (cabeca == NULL)
        return;
    Processo *aux = cabeca;
    do {
        printf("id: %d, tempo restante: %d\n", aux->id, aux->tempoRestante);
        aux = aux->proximo;
    } while (aux != cabeca);
    printf("\n");
}

int main() {
    int quantum = 3;
    Processo *listaProcessos = NULL;
    inserirProcesso(&listaProcessos, 1, 10);
    inserirProcesso(&listaProcessos, 2, 4);
    inserirProcesso(&listaProcessos, 3, 6);
    inserirProcesso(&listaProcessos, 4, 8);
    
    printf("lista de processos inicial:\n");
    imprimirProcessos(listaProcessos);
    
    escalonarProcessos(listaProcessos, quantum);
    
    return 0;
}
