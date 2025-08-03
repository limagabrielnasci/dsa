#include <stdio.h>
#include <stdlib.h>

struct treeNode {
	int valor;
	struct treeNode* esquerda;
	struct treeNode* direita;
};

void emOrdem( struct treeNode* no, int* valores, int* i ) {
	if ( !no ) {
		return;
	}
	emOrdem( no->esquerda, valores, i );
	valores[ (*i)++ ] = no->valor;
	emOrdem( no->direita, valores, i );
}

struct treeNode* construir( int* valores, int ini, int fim ) {
	if ( ini > fim ) {
		return NULL;
	}
	int m = ( ini + fim ) / 2;
	struct treeNode* no = (struct treeNode*)malloc( sizeof( struct treeNode ) );
	no->valor = valores[ m ];
	no->esquerda = construir( valores, ini, m - 1 );
	no->direita = construir( valores, m + 1, fim );
	return no;
}

struct treeNode* balanceBST( struct treeNode* root ) {
	int* valores = (int*)malloc( 10000 * sizeof( int ) );
	int i = 0;

	emOrdem( root, valores, &i );
	struct treeNode* novaRaiz = construir( valores, 0, i - 1 );

	free( valores );
	return novaRaiz;
}

int main() {
	return 0;
}
