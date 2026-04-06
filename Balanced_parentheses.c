#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

int bal_pare(int n , char exp[n]){
    for(int i=0 ; i<n ; i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(top == NULL){
                return -1;
            }
            char t = Top_Stack();
            pop();
            if((exp[i]==')' && t != '(') || (exp[i]=='}' && t != '{') || (exp[i] == ']' && t != '[')){
                return -1;
            }
            
        }
        
    }
    return (top == NULL)?1:-1;
}

int main(){
    int len;
    printf("enter the length of the expression:\n");
    scanf("%d",&len);
    char exp[len];
    printf("enter the expression:\n");
    for(int i=0 ; i<len ; i++){
        scanf(" %c",&exp[i]);
        printf("\n");
    }
    printf("checking the balanced parentheses in the expression...\n");
    int result = bal_pare(len , exp);
    if(result == 1){
        printf("the expression is balnced.");
    }
    else{
        printf("the expression is unbalanced.");
    }
    return 0;
}
