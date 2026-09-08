#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Linked_list.h"

void stack_init(STACK *s){
    s->top = NULL;
}

NODE *create_node(){
    NODE *p = malloc(sizeof(NODE));
    p->next = NULL;
    return p;
}

void push(STACK *s , int data){
    NODE *temp = create_node();
    temp->data = data;
    
    if(s->top == NULL){
        s->top = temp;
        return;
    }

    temp->next = s->top;
    s->top = temp;

}

int pop(STACK *s){
    if(s->top == NULL){
        return -1;
    }
    NODE *temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    if(s->top != NULL){
        printf("top = %d.\n",s->top->data);
    }
    else{
        printf("stack is empty.\n");
    }
    
    free(temp);
    return val;
}

bool is_empty(const STACK *s){
    if(s->top == NULL){
        return 1;
    }
    return 0;
}

int peek(const STACK *s){
    if(is_empty(s)){
        printf("stack is empty.\n");
        return -1;
    }
    return s->top->data;
}

