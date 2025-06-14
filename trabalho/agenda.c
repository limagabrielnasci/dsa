#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME     20
#define TAM_IDADE    3
#define TAM_EMAIL    31
#define TAM_REGISTRO (TAM_NOME + TAM_IDADE + TAM_EMAIL)
#define TAM_TEMP     TAM_NOME

void menu(void *pBuffer) {
    printf("\n1 - Adicionar Pessoa (Nome, Idade, Email)\n");
    printf("2 - Remover Pessoa\n");
    printf("3 - Buscar Pessoa\n");
    printf("4 - Listar Todos\n");
    printf("5 - Sair\n");
    printf("Escolha: ");
    scanf("%d", (int *)pBuffer);
    getchar();
}

void adicionar(void **pBuffer) {
    *((int *)(*pBuffer) + 1) += 1;
    *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + TAM_TEMP + (*((int *)(*pBuffer) + 1)) * TAM_REGISTRO);
    if (!*pBuffer) exit(1);

    char *novo = ((char *)((int *)(*pBuffer) + 2)) + TAM_TEMP + ((*((int *)(*pBuffer) + 1) - 1) * TAM_REGISTRO);

    printf("Nome: ");
    scanf("%19[^\n]%*c", novo);
    printf("Idade: ");
    scanf("%2s%*c", novo + TAM_NOME);
    printf("Email: ");
    scanf("%30s%*c", novo + TAM_NOME + TAM_IDADE);
}

void remover(void **pBuffer) {
    printf("Nome da pessoa pra remover: ");
    scanf("%19[^\n]%*c", (char *)((int *)(*pBuffer) + 2));

    char *base = ((char *)((int *)(*pBuffer) + 2)) + TAM_TEMP;
    int total = *((int *)(*pBuffer) + 1);
    char *p = base;
    char *fim = base + total * TAM_REGISTRO;

    while (p < fim) {
        if (strcmp(p, (char *)((int *)(*pBuffer) + 2)) == 0) {
            if (p != fim - TAM_REGISTRO) {
                memcpy(p, fim - TAM_REGISTRO, TAM_REGISTRO);
            }
            *((int *)(*pBuffer) + 1) -= 1;
            *pBuffer = realloc(*pBuffer, sizeof(int) * 2 + TAM_TEMP + (*((int *)(*pBuffer) + 1)) * TAM_REGISTRO);
            if (!*pBuffer) exit(1);
            printf("Removido.\n");
            return;
        }
        p += TAM_REGISTRO;
    }

    printf("Pessoa não encontrada.\n");
}

void buscar(void *pBuffer) {
    printf("Nome para buscar: ");
    scanf("%19[^\n]%*c", (char *)((int *)pBuffer + 2));

    char *base = ((char *)((int *)pBuffer + 2)) + TAM_TEMP;
    int total = *((int *)pBuffer + 1);
    char *p = base;
    char *fim = base + total * TAM_REGISTRO;

    while (p < fim) {
        if (strcmp(p, (char *)((int *)pBuffer + 2)) == 0) {
            printf("\nNome: %s\nIdade: %s\nEmail: %s\n", p, p + TAM_NOME, p + TAM_NOME + TAM_IDADE);
            return;
        }
        p += TAM_REGISTRO;
    }

    printf("Pessoa não encontrada.\n");
}

void listar(void *pBuffer) {
    int total = *((int *)pBuffer + 1);
    if (total == 0) {
        printf("Nenhuma pessoa.\n");
        return;
    }

    char *base = ((char *)((int *)pBuffer + 2)) + TAM_TEMP;
    char *p = base;
    char *fim = base + total * TAM_REGISTRO;

    while (p < fim) {
        printf("\nNome: %s\nIdade: %s\nEmail: %s\n", p, p + TAM_NOME, p + TAM_NOME + TAM_IDADE);
        p += TAM_REGISTRO;
    }
}

int main() {
    void *pBuffer = calloc(1, sizeof(int) * 2 + TAM_TEMP);
    if (!pBuffer) return 1;

    *((int *)pBuffer + 1) = 0;

    while (1) {
        menu(pBuffer);
        if (*((int *)pBuffer) == 1) {
            adicionar(&pBuffer);
        } else if (*((int *)pBuffer) == 2) {
            remover(&pBuffer);
        } else if (*((int *)pBuffer) == 3) {
            buscar(pBuffer);
        } else if (*((int *)pBuffer) == 4) {
            listar(pBuffer);
        } else if (*((int *)pBuffer) == 5) {
            break;
        }
    }

    free(pBuffer);
    return 0;
}