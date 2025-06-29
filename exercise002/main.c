#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letra;
    int qtd;
} No;

void troca(No *a, No *b) {
    No tmp = *a;
    *a = *b;
    *b = tmp;
}

void ordenar(No heap[], int n) {
    if (n < 2) return;
    if (heap[1].qtd > heap[0].qtd) troca(&heap[1], &heap[0]);
    if (n == 3 && heap[2].qtd > heap[0].qtd) troca(&heap[2], &heap[0]);
}

No remover(No heap[], int *n) {
    No no = heap[0];
    (*n)--;
    heap[0] = heap[*n];
    ordenar(heap, *n);
    return no;
}

void add(No heap[], int *n, No item) {
    heap[*n] = item;
    (*n)++;
    ordenar(heap, *n);
}

char* longestDiverseString(int a, int b, int c) {
    No heap[3];
    int n = 0;
    if (a > 0) add(heap, &n, (No){'a', a});
    if (b > 0) add(heap, &n, (No){'b', b});
    if (c > 0) add(heap, &n, (No){'c', c});

    char *res = malloc(1000);
    int len = 0;

    while (n > 0) {
        No atual = remover(heap, &n);
        if (len >= 2 && res[len - 1] == atual.letra && res[len - 2] == atual.letra) {
            if (n == 0) break;
            No prox = remover(heap, &n);
            res[len++] = prox.letra;
            prox.qtd--;
            if (prox.qtd > 0) add(heap, &n, prox);
            add(heap, &n, atual);
        } else {
            res[len++] = atual.letra;
            if (atual.qtd > 1) res[len++] = atual.letra, atual.qtd--;
            atual.qtd--;
            if (atual.qtd > 0) add(heap, &n, atual);
        }
    }

    res[len] = '\0';
    return res;
}