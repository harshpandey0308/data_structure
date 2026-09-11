#ifndef INFIX_EVAL_H
#define INFIX_EVAL_H

#include<stdbool.h>
#include"Linked_list.h"

int infix_evaluation(STACK *s , STACK *y , char *exp);

int precedence(char *opr1 , char *opr2);

int evaluate_exp(int a , int b , char *opr);

#endif