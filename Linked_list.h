#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

#define MAX_SIZE 10

typedef enum{
    INT , 
    FLOAT,
    CHAR
}Type;

typedef struct NODE{
    void *data;
    Type data_type;
    struct NODE *next;
}NODE;

typedef struct STACk{
    NODE *top;
}STACK;

void stack_init(STACK *s);

void push(STACK *stack , void *data , Type datatype);

void *pop(STACK *stack);

bool is_empty(const STACK *s);

void *peek(const STACK *s);

#endif