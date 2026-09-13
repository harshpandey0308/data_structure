#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

#define MAX_SIZE 10


typedef struct NODE{
    void *data;
    struct NODE *next;
}NODE;

typedef struct STACk{
    NODE *top;
}STACK;

void stack_init(STACK *s);

void push(STACK *stack , void *data);

bool pop(STACK *stack , void *data);

bool is_empty(const STACK *s);

int peek(const STACK *s);

#endif