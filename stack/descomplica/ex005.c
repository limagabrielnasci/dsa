/*
Considere uma pilha que armazene caracteres. Fac¸a uma func¸ao para determinar se ˜
uma string e da forma XY, onde X ´ e uma cadeia formada por caracteres arbitr ´ arios e Y ´
e o reverso de X. Por exemplo, se x = ABCD, ent ´ ao y = DCBA. Considere que x e y s ˜ ao˜
duas strings distintas.
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

int isXYreversed(char *s) {
    int len = strlen(s);

    if (len % 2 != 0) return 0;

    char stack[MAX];
    int top = -1;
    int mid = len / 2;

    for (int i = 0; i < mid; i++) {
        stack[++top] = s[i];
    }

    for (int i = mid; i < len; i++) {
        if (stack[top--] != s[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char s[] = "GABRIELLEIRBAG";
    if (isXYreversed(s)) {
        printf("É da forma XY (Y = reverso de X).\n");
    }
    else {
        printf("Não é da forma XY.\n");
    }
    return 0;
}