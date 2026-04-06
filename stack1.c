#include<stdio.h>
#include<stdlib.h>
#include"stack1.h"

struct node* top = NULL;

struct node* push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
    return top;
}

int Is_empty(){
    return (top == NULL);
}

int pop(){
    if(top == NULL){
        printf("poping not allowed due to empty stack.");
        return '\0';
    }
    struct node* temp = top;
    char item = temp->data;
    top = top->next;
    free(temp);

    return item;
}

int Top_Stack(){
    if(top == NULL){
        printf("the stack is empty.\n");
        return 0;
    }
    return top->data;
}
void print(){
    struct node* temp = top;
    while(temp != NULL){
        printf("\n%c",temp->data);
        temp = temp->next;
    }
}