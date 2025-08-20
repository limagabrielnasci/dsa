#include <stdio.h>
#include <stdlib.h>

int hIndex(int* citations, int citationsSize) {
    int *count = calloc(citationsSize + 1, sizeof(int));
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] >= citationsSize)
            count[citationsSize]++;
        else
            count[citations[i]]++;
    }

    int total = 0;
    for (int i = citationsSize; i >= 0; i--) {
        total += count[i];
        if (total >= i) {
            free(count);
            return i;
        }
    }

    free(count);
    return 0;
}

int main() {
    return 0;
}
