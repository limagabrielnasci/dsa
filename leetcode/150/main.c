#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    typedef struct Stack {
        int item[10000];
        int top;
    } Stack;

    Stack s;
    s.top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];

        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            
            int b = s.item[s.top--];
            int a = s.item[s.top--];

            if (strcmp(token, "+") == 0)
                s.item[++s.top] = a + b;
            else if (strcmp(token, "-") == 0)
                s.item[++s.top] = a - b;
            else if (strcmp(token, "*") == 0)
                s.item[++s.top] = a * b;
            else if (strcmp(token, "/") == 0) {
                if (b == 0) {
                    printf("Error: Division by zero.\n");
                    exit(1);
                }
                s.item[++s.top] = a / b;
            }
        } else {
            s.item[++s.top] = atoi(token);
        }
    }

    return s.item[s.top];
}