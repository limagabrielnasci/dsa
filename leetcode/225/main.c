#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct {
    int item[1000];
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = malloc(sizeof(MyStack));
    stack->top = -1;
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->item[obj->top++] = x;
}

int myStackPop(MyStack* obj) {
    obj->top--;
    return obj->item[obj->top];
}

int myStackTop(MyStack* obj) {
    return obj->item[obj->top - 1];
}

bool myStackEmpty(MyStack* obj) {
    if (obj->top == 0) {
        return true;
    } else {
        return false;
    }
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/