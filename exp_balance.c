#include<stdio.h>
#include"exp_balance.h"
#include<stdbool.h>
#include"Linked_list.h"

bool is_balanced(const char *exp , STACK *s){
    int n = sizeof(exp)/sizeof(exp[0]);

    int balance = 1;
    for(int i=0 ; i<n ; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(s , exp[i]);
            balance = 0;
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if((s->top->data == '(' && exp[i] == ')') || (s->top->data == '{' && exp[i] == '}') || (s->top->data == '[' && exp[i] == ']')){
                balance = 1;
            }
            else{
                balance = 0;
            }
        }
        else{
            continue;
        }
    }

    if(balance == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    STACK s;

    stack_init(&s);

    char *exp = "(4+{9/3*[4*4])";

    if(is_balanced(exp , &s)){
        printf("the expresson is balanced.\n");
    }
    else{
        printf("the expression is not balanced.\n");
    }

    return 0;

}