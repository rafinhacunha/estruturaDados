#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

void inserir(Node** head, int val) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = val;
    novo->next = NULL;
    novo->prev = NULL;

    if (*head == NULL) {
        *head = novo;
    } else {
        Node* temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = novo;
        novo->prev = temp;
    }
}

void remover(Node** head, Node* toRemove) {
    if (*head == NULL || toRemove == NULL)
        return;
    
    if (*head == toRemove)
        *head = toRemove->next;
    if (toRemove->next != NULL)
        toRemove->next->prev = toRemove->prev;
    if (toRemove->prev != NULL)
        toRemove->prev->next = toRemove->next;
    
    free(toRemove);
}

void removerDuplicados(Node** head) {
    if (*head == NULL)
        return;
    
    Node* atual = *head;
 
    while (atual != NULL) {
        Node* runner = atual->next;

        while (runner != NULL) {
            if (runner->data == atual->data) {
                Node* temp = runner->next;
                remover(head, runner);
                runner = temp;
            } else {
                runner = runner->next;
            }
        }
        atual = atual->next;
    }
}

void imprimir(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    
    inserir(&head, 10);
    inserir(&head, 20);
    inserir(&head, 10);
    inserir(&head, 30);
    inserir(&head, 20);
    inserir(&head, 40);
    
    printf("Lista original: ");
    imprimir(head);
    
    removerDuplicados(&head);
    
    printf("Lista sem duplicados: ");
    imprimir(head);
    
    return 0;
}
