#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

typedef struct NODE{
    union data{
        int i_data;
        char c_data;
        float f_data;
    }data;
    struct NODE *next;
}NODE;

typedef struct STACk{
    NODE *top;
}STACK;

void stack_init(STACK *s);

void push(STACK *stack , void *data);

int pop(STACK *stack);

bool is_empty(const STACK *s);

int peek(const STACK *s);

#endif