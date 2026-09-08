#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

typedef struct NODE{
    int data;
    struct NODE *next;
}NODE;

typedef struct STACk{
    NODE *top;
}STACK;

void stack_init(STACK *s);

void push(STACK *stack , int data);

int pop(STACK *stack);

bool is_empty(const STACK *s);

int peek(const STACK *s);

#endif