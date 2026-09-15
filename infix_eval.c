#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include"infix_eval.h"
#include"Linked_list.h"

int evaluate_exp(int *a , int *b , char *opr){
    if(strcmp(opr, "+") == 0){
        return (*a) + (*b);
    }
    else if(strcmp(opr , "-") == 0){
        return (*a) - (*b);
    }
    else if(strcmp(opr , "*") == 0){
        return (*a)*(*b);
    }
    else if(strcmp(opr , "/") == 0){
        return (*b)/(*a);
    }
}

int precedence(char opr){
    if(opr == '+' || opr == '-'){
        return 1;
    }
    else if(opr == '*' || opr == '/'){
        return 2;
    }
    return 0;
}

int infix_evaluation(STACK *s , STACK *y , char *exp){
    int n = strlen(exp);

    int result = 0;
    char *opr1 = malloc(sizeof(char));
    char *opr2 = malloc(sizeof(char));
    int *val1 = malloc(sizeof(int));
    int *val2 = malloc(sizeof(int));

    for(int i=0 ; i<n ; i++){
        if(isdigit(exp[i])){
            int data;
            char new[3];
            if(isdigit(exp[i+1])){
                sprintf(new , "%c%c" , exp[i] , exp[i+1]);
                data = atoi(new);
                i++;
            }
            else{
                data = exp[i] - '0';
            }
            
            push(s, &data , INT);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            if(y->top == NULL){
               push(y , &exp[i] , CHAR);
            }
            else{
                void *ch_data;
                *(char *)ch_data = *(char *)peek(y);
                if(precedence(exp[i]) > precedence(*ch_data)){
                    push(y , &exp[i] , CHAR);
                }
                else{
                    *val1 = *(int *)pop(s);
                    *val2 = *(int *)pop(s);
                    *opr1 = *(char *)pop(y);
                    result = evaluate_exp(val1 , val2 , opr1)
                    push(s , &result , INT);

                    push(y , &exp[i] , CHAR);
                }
            }
            
        }
        else if(exp[i] == '('){
            push(y , &exp[i] , CHAR);
        }
        else if(exp[i] == ')'){
            while(*(char *)y->top->data != "("){
                *val1 = *(int *)pop(s);
                *val2 = *(int *)pop(s);
                *opr1 = *(char *)pop(y);
                result = evaluate_exp(val1 , val2 , opr1);

                push(s , &result , INT);
                pop(y);
            }
        }

    }
    int val = *((int *)s->top->data);

    return val;
}

int main(){
    STACK s;
    STACK y;

    stack_init(&s);
    stack_init(&y);

    char *exp = "((2+3)*5)";

    int value = infix_evaluation(&s , &y , exp);

    printf("the evalauted result is %d.\n",value);

    return 0;
}