#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct{
    char name[30];
    int age;
} Person;

typedef struct {
    Person people[MAX];
    int top;
    int bottom;
    int limit;
} Stack;

void menu();
void reset(Stack *stack);
int empty(Stack *stack);
int full(Stack *stack);
int push(Stack *stack, Person *person);
void pop(Stack *stack, Person *person);
void printStack(Stack *stack);
int removeByName(Stack *stack, char *name);

int main() {
    menu();
}

void menu() {
    Stack stack;
    reset(&stack);
    Person person;
    char nameToRemove[30];

    int option;
    for (;;) {
        printf("ADD (0)\nDELETE PERSON (1)\nDELETE BY NAME (2)\nCLEAR STACK (3)\nPRINT STACK (4)\nEXIT (5)\n");
        printf("OPTION: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 0:
                if (full(&stack)) {
                    printf("---STACK IS FULL---\n\n");
                } else {
                    printf("Name: ");
                    scanf(" %[^\n]", &person.name);
                    printf("Age: ");
                    scanf("%d", &person.age);
                    printf("\n");
                    push(&stack, &person);
                    printf("---PERSON ADDED---\n\n");
                }
                break;
            case 1:
                if (empty(&stack)) {
                    printf("---STACK IS EMPTY---\n\n");
                } else {
                    pop(&stack, &person);
                    printf("---PERSON REMOVED---\n\n");
                    printf("Name: %s, Age: %d\n\n", person.name, person.age);
                }
                break;
            case 2:
                if (empty(&stack)) {
                    printf("---STACK IS EMPTY---\n\n");
                } else {
                    printf("Name to remove: ");
                    scanf(" %[^\n]", &nameToRemove);
                    printf("\n");
                    if (removeByName(&stack, nameToRemove)) {
                        printf("---PERSON REMOVED---\n\n");
                    } else {
                        printf("---PERSON NOT FOUND---\n\n");
                    }
                }
                break;
            case 3:
                reset(&stack);
                printf("---STACK IS EMPTY---\n\n");
                break;
            case 4:
                printStack(&stack);
                break;
            case 5:
                printf("GOODBYE!\n");
                exit(0);
                break;
            default:
                printf("---INVALID OPTION---\n\n");
        }
    }
}

void reset(Stack *stack) {
    stack->top = 0;
    stack->bottom = 0;
    stack->limit = MAX;
}

int empty(Stack *stack) {
    return stack->top == 0;
}

int full(Stack *stack) {
    return stack->top == MAX;
}

int push(Stack *stack, Person *person) {
    if (!full(stack)) {
        stack->people[stack->top] = *person;
        stack->top++;
        return 1;
    } else {
        return 0;
    }
}

void pop(Stack *stack, Person *person) {
    if (empty(stack)) return;
    stack->top--;
    *person = stack->people[stack->top];
}

void printStack(Stack *stack) {
    printf("-----STACK-----\n\n");
    for (int i = stack->top - 1; i >= 0; i--) {
        printf("Name: %s\nAge: %d\n\n", stack->people[i].name, stack->people[i].age);
    }
}

int removeByName(Stack *stack, char *name) {
    for (int i = stack->top - 1; i >= 0; i--) {
        if (strcmp(stack->people[i].name, name) == 0) {
            for (int j = i; j < stack->top - 1; j++) {
                stack->people[j] = stack->people[j + 1];
            }
            stack->top--;
            return 1;
        }
    }
    return 0;
}