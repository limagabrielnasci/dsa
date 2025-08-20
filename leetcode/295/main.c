#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Heap;

Heap* createHeap(int capacity) {
    Heap *h = malloc(sizeof(Heap));
    h->data = malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapPush(Heap *h, int val) {
    int i = h->size++;
    h->data[i] = val;
    while (i > 0 && h->data[(i-1)/2] < h->data[i]) {
        swap(&h->data[i], &h->data[(i-1)/2]);
        i = (i-1)/2;
    }
}

int maxHeapPop(Heap *h) {
    int ret = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, largest = i;
        if (l < h->size && h->data[l] > h->data[largest]) largest = l;
        if (r < h->size && h->data[r] > h->data[largest]) largest = r;
        if (largest == i) break;
        swap(&h->data[i], &h->data[largest]);
        i = largest;
    }
    return ret;
}

void minHeapPush(Heap *h, int val) {
