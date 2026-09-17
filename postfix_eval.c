#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Linked_list.h"

int evaluate(int op1 , int op2 , char opr){
    if(opr == '+') return op1 + op2;
    else if(opr == '-') return op1 - op2;
    else if(opr == '*') return op1 * op2;
    else if(opr == '/'){
        if(op1 > op2){
            return op1/op2;
        }
        else{
            return op2/op1;
        }
    }

}

int postfix_evaluation(STACK *s , char *exp){
    int a = strlen(exp);
    
    for(int i=0 ; i<a ; i++){
        if(isdigit(exp[i])){
            char new[3];
            int data;
            if(isdigit(exp[i+1])){
                sprintf(new , "%c%c" , exp[i] , exp[i+1]);
                data = atoi(new);
                i++;
            }
            else{
                data = exp[i] - '0';
            }
            
            push(s , &data , INT);
            NODE *temp = s->top;
            while(temp != NULL){
                printf("value = %d.\n",*(int *)temp->data);
                temp = temp->next;
            }
            
            //pop(s);
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            int op1 = *(int *)pop(s);
            int op2 = *(int *)pop(s);

            if(op1 == -1){
                op1 = 0;
            }
            else if(op2 == -1){
                op2 = 0;
            }

            printf("op1 = %d , op2 = %d.\n",op1 , op2);

            int result = evaluate(op1 , op2 , exp[i]);
            printf("result = %d.\n",result);
            push(s , &result , INT);
        }
        else if(exp[i] == ' '){
            continue;
        }
        
    }
    int val = *(int *)s->top->data;
    return val;
}

int main(){
    STACK s;

    stack_init(&s);

    char *exp = "15 20 + 5 /";

    int val = postfix_evaluation(&s , exp);

    printf("EVALUATED RESULT : %d.\n",val);

    return 0;
}