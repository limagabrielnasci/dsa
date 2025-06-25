#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next; // ponteiro pro próximo elemento
} Node;

// variáveis ponteiros globais que guardam referência
// para a cabeça da lista e o nó corrente
// cabeça da lista encadeada (começa com NULL)
Node *head = NULL;
Node *current = NULL;

Node *create_list(int value) {
    // aloca espaço em memória
    Node *p = (Node *)malloc(sizeof(Node));

    if (!p) {
        printf("\nMemory allocation failed\n");
        return NULL;
    }

    p->value = value; // atribui o valor
    p->next = NULL;   // o próximo é NULL

    // faz a cabeça e o corrente apontar pra p
    head = current = p;

    // retorna o ponteiro alocado
    return p;
}

Node *add_to_list(int value) {
    // verifica se a cabeça é NULL (lista vazia)
    if (head == NULL) {
        return create_list(value);
    }

    Node *p = (Node *)malloc(sizeof(Node));

    if (!p) {
        printf("\nMemory allocation failed\n");
        return NULL;
    }

    p->value = value;
    p->next = NULL;

    // para inserção no final, fazemos com que o próximo do nó
    // corrente aponte para p
    current->next = p;

    // corrente passa a ser p
    current = p;

    // retorna o ponteiro alocado
    return p;
}

void print_list() {
    // variável ponteiro "aux" para percorrer a lista
    // inicialmente aponta para "head"
    Node *aux = head;

    while (aux != NULL) {
        // imprime o conteúdo
        printf("%d\n", aux->value);

        // aponta pro próximo nó da lista
        aux = aux->next;
    }
}

// função para verificar se a lista está vazia
// retorna 1 se estiver vazia e 0 caso contrário
int is_list_empty() {
    return head == NULL;
}

// recebe o valor a ser buscado e um ponteiro para ant
// que servirá para guardar o anterior do elemento encontrado
Node *find_element(int value, Node **previous) {
    if (is_list_empty()) {
        return NULL;
    }

    // variável "p" para percorrer a lista
    Node *p = head;
    // variável "aux_prev" para guardar o anterior
    Node *aux_prev = NULL;
    // flag "found" que indica se achou o elemento
    int found = 0;

    while (p != NULL) {
        if (p->value == value) {
            found = 1;
            break;
        }
        // atualiza o "aux_prev"
        aux_prev = p;
        // aponta para o próximo
        p = p->next;
    }

    if (found) {
        // se "previous" for diferente de NULL
        if (previous) {
            *previous = aux_prev; // guarda "aux_prev"
        }
        return p;
    }

    // se chegou aqui, não achou
    return NULL;
}

int remove_element(int value) {
    // variável que guarda a referência para o nó anterior
    // do elemento que vai ser removido
    Node *previous = NULL;

    // busca pelo elemento a ser removido
    // passa a referência para o "previous"
    // elem é o elemento que será removido
    Node *elem = find_element(value, &previous);

    if (elem == NULL) {
        return 0;
    }

    if (previous != NULL) {
        previous->next = elem->next;
    }

    if (elem == current) {
        current = previous;
    }

    if (elem == head) {
        head = elem->next;
    }

    free(elem);
    return 1;
}

int main() {
    if (!is_list_empty()) {
        printf("The list is not empty\n\n");
    } else {
        printf("The list is empty\n\n");
    }

    printf("Creating a list...\n\n");
    create_list(10);

    printf("Adding nodes to the list...\n\n");
    add_to_list(20);
    add_to_list(30);
    add_to_list(40);
    add_to_list(50);

    printf("Printing the nodes in the list:\n");
    print_list();

    if (find_element(10, NULL)) {
        printf("\nElement 10 found!\n");
    } else {
        printf("\nElement 10 not found\n");
    }

    if (find_element(100, NULL)) {
        printf("\nElement 100 found!\n");
    } else {
        printf("\nElement 100 not found\n");
    }

    if (remove_element(30)) {
        printf("\nElement 30 successfully removed!\n");
    } else {
        printf("Failed to remove element 30\n");
    }

    print_list();

    return 0;
}