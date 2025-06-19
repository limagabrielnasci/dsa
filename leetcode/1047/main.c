#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char string[100];
    int top;
} Stack;

char* removeDuplicates(char* s) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (stack.top >= 0 && stack.string[stack.top] == s[i]) {
            stack.top--;
        } else {
            stack.string[++stack.top] = s[i];
        }
    }
    stack.string[stack.top + 1] = '\0';
    return strdup(stack.string);
}