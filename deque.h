#ifndef DEQUE_H
#define DEQUE_H

#include<stdbool.h>
#include<stddef.h>

#define CAPACITY 5

typedef struct deque{
    int data[CAPACITY];
    size_t front;
    size_t size;
}deque;

void _init_deque(deque *dq);

bool push_front(deque *dq , int data);

bool push_rear(deque *dq , int data);

bool pop_front(deque *dq);

bool pop_rear(deque *dq);

void print_que(deque *dq);

#endif