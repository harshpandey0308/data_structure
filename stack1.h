#ifndef STACK1_H
#define STACK1_H

#include"node1.h"

extern struct node* top;

struct node* push(int x);
int pop();
int Top_Stack();
void print();
int Is_empty();

#endif