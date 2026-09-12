#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include"infix_eval.h"
#include"Linked_list.h"

int evaluate_exp(int a , int b , char *opr){
    if(strcmp(opr, "+") == 0){
        return a + b;
    }
    else if(strcmp(opr , "-") == 0){
        return a - b;
    }
    else if(strcmp(opr , "*") == 0){
        return a*b;
    }
    else if(strcmp(opr , "/") == 0){
        return b/a;
    }
}

int precedence(char *opr1 , char *opr2){
    if((strcmp(opr1 , "*") == 0 || strcmp(opr1 , "/") == 0) && (strcmp(opr2 , "+") == 0 || strcmp(opr2 , "-") == 0)){
        return 1;
    }
    else if((strcmp(opr1 , "+") == 0 || strcmp(opr1 , "-") == 0) && (strcmp(opr2 , "*") == 0 || strcmp(opr2 , "/") == 0)){
        return 0;
    }
    else if((strcmp(opr1 , "*") == 0 && strcmp(opr2 , "/") == 0) || (strcmp(opr1 , "/") == 0 && strcmp(opr2 , "*") == 0)){
        return -1;
    }
    else if((strcmp(opr1 , "+") == 0 && strcmp(opr2 , "-") == 0) || strcmp(opr1 , "-") == 0 && strcmp(opr2 , "+") == 0){
        return -1;
    }
}

int infix_evaluation(STACK *s , STACK *y , char *exp){
    int n = strlen(exp);

    for(int i=0 ; i<n ; i++){
        if(isdigit(exp[i])){
            push(s,&exp[i]);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            push(y , &exp[i]);
        }
        else if(exp[i] == '('){
            push(y , &exp[i]);
        }
        else if(exp[i] == ')'){
            int result = 0;
            int val1 = pop(s);
            int val2 = pop(s);
            char *opr1 = pop(y);
            char *opr2 = pop(y);

            if(opr1 == NULL){
                perror("No operations left.");
                exit(-1);
            }
            else if(opr2 == NULL){
                result = evaluate_exp(val1 , val2 , opr1);
            }

            int precedence_flag = precedence(opr1 , opr2);

            if(precedence_flag == 1){
                result = evaluate_exp(val1 , val2 , opr1);
            }
            else if(precedence_flag == 0){
                result = evaluate_exp(val1 , val2 , opr2);
            }
            else if(precedence_flag == -1){
                result = evalauate_exp(val1 , val2 , opr2);
                push(y , opr1);
            }

            push(s , &result);
        }

    }

    return s->top->data.i_data;
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