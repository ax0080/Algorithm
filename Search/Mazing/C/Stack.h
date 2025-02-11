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
    

} NodeStack;

typedef struct {
    NodeStack nodestack;

    void (*init)(NodeStack* ,int );
    bool (*isEmpty)(NodeStack*)


} NodeWrapper;

#endif