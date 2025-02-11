#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  


typedef struct {
    int *data;     
    int top;       
    int capacity;  
} Stack;


typedef struct {
    Stack stack;

    void (*init)(Stack *, int);
    bool (*isEmpty)(Stack *);
    void (*push)(Stack *, int);
    int (*pop)(Stack *);
    int (*peek)(Stack *);
    void (*expand)(Stack *);
    void (*free)(Stack *);
} StackWrapper;

void initStack(Stack *stack, int initialCapacity);
bool isEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void expandStack(Stack *stack);
void freeStack(Stack *stack);
StackWrapper createStackWrapper(int initialCapacity);

#endif 
