#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int conteudo;
    struct Nodo *prox; // ponteiro pro próximo elemento
} Nodo;

// variaveis ponteiros globais que guardam referência
// para a cabeça da lista e o nó corrente
// cabeça da lista encadeada (começa com NULL)
Nodo *cabeca = NULL;
Nodo *corrente = NULL;

Nodo *criar_lista(int valor) {

    // aloca espaço em memória
    Nodo *p = (Nodo *)malloc(sizeof(Nodo));

    if (!p) {
        printf("\nFalha ao alocar memória\n");
        return NULL;
    }

    p->conteudo = valor; // atribui o valor
    p->prox = NULL; // o próximo é NULL

    // faz a cabeça e o corrente apontar pra p
    cabeca = corrente = p;

    // retorna o ponteiro alocado
    return p;
}

Nodo *adicionar_lista(int valor) {

    // verifica se a cabeca eh NULL (lista vazia)
    if (cabeca == NULL) {
        return criar_lista(valor);
    }

    Nodo *p = (Nodo *)malloc(sizeof(Nodo));

    if (!p) {
        printf("\nFalha ao alocar memória\n");
        return NULL;
    }

    p->conteudo = valor;
    p->prox = NULL;

    // para inserção no final, fazemos com que o próximo do nó
    // corrente aponte para p
    corrente->prox = p;

    // corrente passa a ser p
    corrente = p;

    // retorna o ponteiro alocado
    return p;
}

void imprimir_lista() {
    // variavel ponteiero "aux" para percorrer a lista
    // inicialmente aponta para "cabeca"
    Nodo *aux = cabeca;

    while (aux != NULL) {
        // imprime o conteúdo
        printf("%d\n", aux->conteudo);

        // aponta pro próximo nó da lista
        aux = aux->prox;
    }
}

// função para verificar se a lista está vazia
// retorna 1 se estiver vazia e 0 caso contrário
int lista_vazia() {
    if (cabeca == NULL) {
        return 1;
    }
    return 0;
}

// recebe o valor a ser busca e um ponteiro para ant
// que servirá para guardar o anterior do elemento encontrado
Nodo *buscar_elemento(int valor, Nodo **anterior) {
    if (lista_vazia() == 1) {
        return NULL;
    }

    // variavel "p" para percorrer a lista
    Nodo *p = cabeca;
    // variavel "aux_ant" para guardar o anterior
    Nodo *aux_ant = NULL;
    // flag "achou" que indica se achou o elemento
    int achou = 0;

    while (p != NULL) {
        if (p->conteudo == valor) {
            achou = 1;
            break;
        }
        // atualiza o "aux_ant"
        aux_ant = p;
        // aponta para o próximo
        p = p->prox;
    }

    if (achou == 1) {
        // se "ant" for diferente de NULL
        if (anterior) {
            *anterior = aux_ant; // guarda "aux_ant"
        }
        return p;
    }

    // se chegou aqui, não achou
    return NULL;
}

int remover_elemento(int valor) {
    // variavel que guarda a referência para o nó anterior
    // do elemento que vai ser removido
    Nodo *anterior = NULL;

    // busca pelo elemento a ser removido
    // passa a referencia para o "anterior"
    // elem é o elemento que será removido
    Nodo *elem = buscar_elemento(valor, &anterior);

    if (elem == NULL) {
        return 0;
    }

    if (anterior != NULL) {
        anterior->prox = elem->prox;
    }

    if (elem == corrente) {
        corrente = anterior;
    }

    if (elem == cabeca) {
        cabeca = elem->prox;
    }

    free(elem);
    elem = NULL;
    return 1;
}

int main() {
    if (lista_vazia() == 0) {
        printf("A lista não está vazia\n\n");
    } else {
        printf("Lista vazia\n\n");
    }

    printf("Criando uma lista...\n\n");
    criar_lista(10);

    printf("Adicionando nós na lista...\n\n");
    adicionar_lista(20);
    adicionar_lista(30);
    adicionar_lista(40);
    adicionar_lista(50);

    printf("Imprimindo os nós da lista:\n");
    imprimir_lista();

    if (buscar_elemento(10, NULL) != NULL) {
        printf("\nElemento 10 encontrado!\n");
    } else {
        printf("\nElemento 10 não encontrado\n");
    }
    if (buscar_elemento(100, NULL) != NULL) {
        printf("\nElemento 100 encontrado!\n");
    } else {
        printf("\nElemento 100 não encontrado\n");
    }

    if (remover_elemento(30)) {
        printf("\nElemento 30 removido com sucesso!\n");
    } else {
        printf("Não foi possível remover o elemento 30\n");
    }

    imprimir_lista();

    return 0;
}