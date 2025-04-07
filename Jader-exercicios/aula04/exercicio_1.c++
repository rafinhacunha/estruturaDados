#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    double itens[MAX];
    int topo;
} Pilha;

void inicializa(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilha(Pilha *p, double valor) {
    if (estaCheia(p)) {
        printf("pilha cheia!\n");
        exit(1);
    }
    p->itens[++(p->topo)] = valor;
}

double desempilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("pilha vazia!\n");
        exit(1);
    }
    return p->itens[(p->topo)--];
}

int main() {
    char expressao[256];
    Pilha p;
    
    inicializa(&p);
    
    printf("digite a expressao pos-fixa (com espacos entre numeros e operadores):\n");
    fgets(expressao, sizeof(expressao), stdin);
    
    char *token = strtok(expressao, " \n");
    
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            double num = atof(token);
            empilha(&p, num);
        } else {
            double op2 = desempilha(&p);
            double op1 = desempilha(&p);
            double resultado;
            
            switch (token[0]) {
                case '+':
                    resultado = op1 + op2;
                    break;
                case '-':
                    resultado = op1 - op2;
                    break;
                case '*':
                    resultado = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("divisao por zero!\n");
                        exit(1);
                    }
                    resultado = op1 / op2;
                    break;
                default:
                    printf("operador invalido (%s)!\n", token);
                    exit(1);
            }
            empilha(&p, resultado);
        }
        token = strtok(NULL, " \n");
    }
    
    if (p.topo != 0) {
        printf("expressao invalida\n");
        return 1;
    }
    
    double resultadoFinal = desempilha(&p);
    printf("resultado: %lf\n", resultadoFinal);
    
    return 0;
}
