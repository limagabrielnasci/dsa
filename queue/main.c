#include <stdio.h>
#include <stdlib.h>

// FIFO - first in, first out >>> primeiro a entrar, primeiro a sair

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void push(Node **queue, int num) {
    Node *temp, *new = malloc(sizeof(Node));
    if (new == NULL) {
        printf("\nMemory allocation error\n");
    }
    new->value = num;
    new->next = NULL;
    if (*queue == NULL) {
        *queue = new;
    } else {
        temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

int pop(Node **queue) {
    if (*queue == NULL) {
        return -1;
    }

    /*
    cria um nó temporário que aponta pro primeiro nó da fila
    declara uma variável do tipo int que recebe o valor do primeiro nó da fila
    faz o primeiro nó real da fila receber o segundo nó
    */
    Node *temp = *queue;
    int val = temp->value;
    *queue = temp->next;
    free(temp);
    return val;
}

void printQueue(Node *queue) {
    Node *temp = queue;
    while (temp != NULL) {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main() {
    Node *queue = NULL;

    printf("\n--- QUEUE ---\n");
    push(&queue, 3);
    push(&queue, 9);
    push(&queue, 15);
    printQueue(queue);

    
    printf("\n--- QUEUE ---\n");
    pop(&queue);
    printQueue(queue);

    return 0;
}