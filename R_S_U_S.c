#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"

int main(){
    
    char name[7];
    int n = strlen(name);
    printf("enter the name:\n");
    for(int j=0 ; j<n ; j++){
        scanf("%c",&name[j]);
    }
    printf("push the string into the stack:\n");
    for(int i=0 ; i<n ; i++){
        push(name[i]);
    }
    print();
    printf("reverse the string using stack:\n");
    for(int i=0 ; i<n ; i++){
        if(!Is_empty()){
            name[i] = Top_Stack();
            pop();
        }
    }
    for(int i=0 ; i<n ; i++){
        printf("%c",name[i]);
    }
    return 0;
}

