/*
Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra de um
texto terminado por ponto (.) preservando a ordem das palavras. Por exemplo, dado o
texto:
ESTE EXERC´ICIO E MUITO F ´ ACIL. ´
A sa´ıda deve ser:
ETSE OIC´ICREXE E OTIUM LIC ´ AF
*/

#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char item[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->item[++(s->top)] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->item[(s->top)--];
    }
    return '\0';
}

void reverseWords(char *s) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && s[i] != '.') {
            push(&stack, s[i]);
        } else {
            while (stack.top != -1) {
                putchar(pop(&stack));
            }
            if (s[i] == ' ' || s[i] == '.') {
                putchar(s[i]);
            }
        }
    }
    putchar('\n');
}

int main() {
    char texto[] = "GABRIEL EH FELIZ.";
    reverseWords(texto);
    return 0;
}