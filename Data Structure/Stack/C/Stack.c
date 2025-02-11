#include "stack.h"

// initialize
void initStack(Stack *stack, int initialCapacity) {
    stack->data = (int *)malloc(initialCapacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = -1;
    stack->capacity = initialCapacity;
}

// empty check
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// auto expand
void expandStack(Stack *stack) {
    stack->capacity *= 2;
    stack->data = (int *)realloc(stack->data, stack->capacity * sizeof(int));
    if (!stack->data) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }
    printf("Stack expanded to capacity %d\n", stack->capacity);
}

// push
void push(Stack *stack, int value) {
    if (stack->top == stack->capacity - 1) {
        expandStack(stack);
    }
    stack->data[++stack->top] = value;
    printf("Pushed %d to stack.\n", value);
}

// pop
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1; 
    }
    return stack->data[stack->top--];
}

// peek, but not pop
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1; 
    }
    return stack->data[stack->top];
}

// release
void freeStack(Stack *stack) {
    free(stack->data);
}

// StackWrapper
StackWrapper createStackWrapper(int initialCapacity) {
    StackWrapper wrapper;
    
    wrapper.init = initStack;
    wrapper.isEmpty = isEmpty;
    wrapper.push = push;
    wrapper.pop = pop;
    wrapper.peek = peek;
    wrapper.expand = expandStack;
    wrapper.free = freeStack;

    wrapper.init(&wrapper.stack, initialCapacity);
    return wrapper;
}
