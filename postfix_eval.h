#ifndef POSTFIX_EVAL_H
#define POSTFIX_EVAL_H

#include"Linked_list.h"

int evaluate(int op1 , int op2 , char opr);

int postfix_evaluation(STACK *s , char *exp);

#endif