// A stack that can auto-expand when its capacity isn't enough
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int top_addr;
    int capacity;
} Stack;

typedef struct {
    Stack Stack;

    void (*init) (Stack*, int);
    int (*isEmpty)(Stack *);
    void (*push)(Stack*, int);
    int (*pop)(Stack *);
    int (*peek)(Stack *); // see top element
    void (*expand)(Stack *);
    void (*free)(Stack *);
} StackWrapper;

// initialize stack
void initStack(Stack *stack, int initialCapacity) {
    stack->data = (int *)malloc(initialCapacity * sizeof(int));
    if (!stack->data) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    stack->top_addr = -1;
    stack->capacity = initialCapacity;
}

// check whether stack is empty
int isEmpty(Stack *stack) {
    return stack->top_addr == -1;
}

// expand stack
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
    if (stack->top_addr == stack->capacity - 1) {
        expandStack(stack);
    }
    stack->data[++stack->top_addr] = value;
    printf("Pushed %d to stack.\n", value);
}

// pop
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->data[stack->top_addr--];
}

// peek, but not pop
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->data[stack->top_addr];
}

// release
void freeStack(Stack *stack) {
    free(stack->data);
}

// initialize StackWrapper
StackWrapper createStackWrapper(int initialCapacity) {
    StackWrapper wrapper;
    
    wrapper.init = initStack;
    wrapper.isEmpty = isEmpty;
    wrapper.push = push;
    wrapper.pop = pop;
    wrapper.peek = peek;
    wrapper.expand = expandStack;
    wrapper.free = freeStack;

    wrapper.init(&wrapper.Stack, initialCapacity);
    return wrapper;
}

int main(){
    StackWrapper stackWrapper = createStackWrapper(2); // initial capacity is 2

    stackWrapper.push(&stackWrapper.Stack, 10);
    stackWrapper.push(&stackWrapper.Stack, 20);
    stackWrapper.push(&stackWrapper.Stack, 30); 

    printf("Top element is %d\n", stackWrapper.peek(&stackWrapper.Stack));

    stackWrapper.pop(&stackWrapper.Stack);
    stackWrapper.pop(&stackWrapper.Stack);

    printf("Stack is %s\n", stackWrapper.isEmpty(&stackWrapper.Stack) ? "empty" : "not empty");

    stackWrapper.free(&stackWrapper.Stack);
    return 0;
}