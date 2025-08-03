#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int valor;
    struct TreeNode* esquerda;
    struct TreeNode* direita;
};

struct TreeNode* balanceBST(struct TreeNode* root) {
    int* valores = malloc(10000 * sizeof(int));
    int indice = 0;
    void emOrdem(struct TreeNode* no) {
        if (!no) return;
        emOrdem(no->direita);
        valores[indice++] = no->valor;
        emOrdem(no->esquerda);
    }
    emOrdem(root);
}

int main() {
    return 0;
}