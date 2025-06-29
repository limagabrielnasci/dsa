#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letter;
    int count;
} Node;

void swap(Node *a, Node *b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort(Node heap[], int n) {
    if (n < 2) return;
    if (heap[1].count > heap[0].count) swap(&heap[1], &heap[0]);
    if (n == 3 && heap[2].count > heap[0].count) swap(&heap[2], &heap[0]);
}

Node removeMax(Node heap[], int *n) {
    Node node = heap[0];
    (*n)--;
    heap[0] = heap[*n];
    sort(heap, *n);
    return node;
}

void insert(Node heap[], int *n, Node item) {
    heap[*n] = item;
    (*n)++;
    sort(heap, *n);
}

char* longestDiverseString(int a, int b, int c) {
    Node heap[3];
    int n = 0;
    if (a > 0) insert(heap, &n, (Node){'a', a});
    if (b > 0) insert(heap, &n, (Node){'b', b});
    if (c > 0) insert(heap, &n, (Node){'c', c});

    char *result = malloc(1000);
    int len = 0;

    while (n > 0) {
        Node current = removeMax(heap, &n);
        if (len >= 2 && result[len - 1] == current.letter && result[len - 2] == current.letter) {
            if (n == 0) break;
            Node next = removeMax(heap, &n);
            result[len++] = next.letter;
            next.count--;
            if (next.count > 0) insert(heap, &n, next);
            insert(heap, &n, current);
        } else {
            result[len++] = current.letter;
            if (current.count > 1) result[len++] = current.letter, current.count--;
            current.count--;
            if (current.count > 0) insert(heap, &n, current);
        }
    }

    result[len] = '\0';
    return result;
}

int main() {
    char *s = longestDiverseString(1, 1, 7);
    printf("%s\n", s);
    free(s);
    return 0;
}