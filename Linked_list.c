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

void push(STACK *s , void *data){
    NODE *temp = create_node();
    temp->data = data;
    
    if(s->top == NULL){
        s->top = temp;
        return;
    }

    temp->next = s->top;
    s->top = temp;

}

bool pop(STACK *s , void *data){
    if(s->top == NULL){
        return false;
    }
    NODE *temp = s->top;
    
    data = &(temp->data);
    
    s->top = temp->next;
    if(s->top != NULL){
        printf("top = %d.\n",s->top->data);
    }
    else{
        printf("stack is empty.\n");
        return false;
    }
    
    free(temp);
    return true;
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

