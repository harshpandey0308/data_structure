#include<stdio.h>
#include<ctype.h>
#include"Linked_list.h"

int evaluate(int op1 , int op2 , char opr){
    if(opr == '+') return op1 + op2;
    else if(opr == '-') return op1 - op2;
    else if(opr == '*') return op1 * op2;
    else if(opr == '/') return op1 / op2;

}

int postfix_evaluation(STACK *s , char *exp){
    int n = sizeof(exp)/sizeof(exp[0]);
    for(int i=0 ; i<n ; i++){
        if(isdigit(exp[i])){
            int data = exp[i] - '0';
            printf("data pushed into the stack : %d.\n",data);
            push(s , data);
            NODE *temp = s->top;
            while(temp != NULL){
                printf("value = %d.\n",temp->data);
                temp = temp->next;
            }
            //pop(s);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            int op1 = pop(s);
            int op2 = pop(s);

            if(op1 == -1){
                op1 = 0;
            }
            else if(op2 == -1){
                op2 = 0;
            }

            printf("op1 = %d , op2 = %d.\n",op1 , op2);

            int result = evaluate(op1 , op2 , exp[i]);
            printf("result = %d.\n",result);
            push(s , result);
        }
        
    }
    return s->top->data;
}

int main(){
    STACK s;

    stack_init(&s);

    char *exp = "342*+";

    int val = postfix_evaluation(&s , exp);

    printf("EVALUATED RESULT : %d.\n",val);

    return 0;
}