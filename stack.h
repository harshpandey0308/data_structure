#ifndef STACK_H
#define STACK_H

#include"node.h"

extern struct node* top;

struct node* push(char x);
char pop();
char Top_Stack();
void print();
int Is_empty();

#endif