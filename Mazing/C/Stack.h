#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

typedef struct {
    int x;
    int y;
    int data;
} Node; 

typedef struct {
    Node *node;
    int top;
    int capacity;
} NodeStack;

typedef struct {
    NodeStack nodestack;

    void (*init)(NodeStack* ,int );
    bool (*isEmpty)(NodeStack*);
    void (*push)(NodeStack* ,int );
    int (*pop)(NodeStack* );
    int (*peek)(NodeStack* );
    void (*expand)(NodeStack* );
    void (*free)(NodeStack* );
} NodeWrapper;

void init(NodeStack *nodestack, int initial_capacity);
bool isEmpty(NodeStack *nodestack);
void push(NodeStack *nodestack);
int pop(NodeStack *nodestack);
int peek(NodeStack *nodestack);
void expand(NodeStack *nodestack);
void free(NodeStack *nodestack);

#endif