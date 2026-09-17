#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include"infix_eval.h"
#include"Linked_list.h"

int evaluate_exp(int *a , int *b , char *opr){
    if(*opr == '+'){
        return (*a) + (*b);
    }
    else if(*opr == '-'){
        return (*b) - (*a);
    }
    else if(*opr == '*'){
        return (*a)*(*b);
    }
    else if(*opr == '/'){
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
    int *val1 = malloc(sizeof(int));
    int *val2 = malloc(sizeof(int));

    for(int i=0 ; i<n ; i++){
        if(isdigit(exp[i])){
            int data = 0;
            while(isdigit(exp[i])){
                data = data*10 + (exp[i] - '0');
                i++;
            }
            i--;
            
            push(s, &data , INT);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            if(y->top == NULL){
               push(y , &exp[i] , CHAR);
            }
            else{
                char ch_data = *(char *)peek(y);
                if(precedence(exp[i]) > precedence(ch_data)){
                    push(y , &exp[i] , CHAR);
                }
                else{
                    val1 = (int *)pop(s);
                    val2 = (int *)pop(s);
                    opr1 = (char *)pop(y);
                    result = evaluate_exp(val1 , val2 , opr1);
                    push(s , &result , INT);

                    push(y , &exp[i] , CHAR);
                }
            }
            
        }
        else if(exp[i] == '('){
            push(y , &exp[i] , CHAR);
        }
        else if(exp[i] == ')'){
            while(*(char *)y->top->data != '('){
                val1 = (int *)pop(s);
                val2 = (int *)pop(s);
                opr1 = (char *)pop(y);
                result = evaluate_exp(val1 , val2 , opr1);

                push(s , &result , INT);
                
            }
            pop(y);
        }

    }

    while(!is_empty(y)){
        val1 = (int *)pop(s);
        val2 = (int *)pop(s);
        opr1 = (char *)pop(y);

        result = evaluate_exp(val1 , val2 , opr1);

        push(s , &result , INT);
    }

    free(val1);
    free(val2);
    free(opr1);

    int val = *((int *)s->top->data);

    return val;
}

int main(){
    STACK s;
    STACK y;

    stack_init(&s);
    stack_init(&y);

    char *exp = "((100/2)*5)";

    int value = infix_evaluation(&s , &y , exp);

    printf("the evalauted result is %d.\n",value);

    return 0;
}