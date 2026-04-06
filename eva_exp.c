#include<stdio.h>
#include<stdlib.h>
#include"stack1.h"

int operation(int op1 , int op2 , int opr);

int evaluate_exp(int n , char exp[n]){
    int op1 , op2;
    int result;
    for(int i=n-1 ; i>=0 ; i--){
        if(exp[i]>='0' && exp[i]<='9'){
            push(exp[i] - '0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            op1 = pop();
            op2 = pop();
            result = operation(op1 , op2 , exp[i]);
            if(result == -1){
                printf("the operation is not valid");
                return -1;
            }
            else{
                push(result);
            }
        }
    }
    if(Is_empty()){
        printf("invalid expression. please ente rthe valid expression.");
        return -1;
    }
    return pop();
}

int operation(int op1 , int op2 , int opr){
    if(opr == '+'){
        return op1 + op2;
    }
    else if(opr == '-'){
        return op1 - op2;
    }
    else if(opr == '*'){
        return op1 * op2;
    }
    else if(opr == '/'){
        if(op2 == 0){
            printf("the division is not possible.");
            return -1;
        }
        return op1 / op2;
    }
    else{
        return -1;
    }
}

int main(){
    int n ;
    printf("enter the length of the expression:\n");
    scanf("%d",&n);

    char exp[n];
    printf("enter the expression in the array:\n");
    for(int i=0 ; i<n ; i++){
        scanf(" %c",&exp[i]);
    }
    printf("the expression is:\n");
    for(int i=0 ; i<n ; i++)
    {
        printf("%c",exp[i]);
    }

    printf("evaluating the expression....\n");

    int eval_res = evaluate_exp(n , exp);

    if(eval_res != -1){
        printf("the final evaluation result of expression is %d",eval_res);
    }

    return 0;
}