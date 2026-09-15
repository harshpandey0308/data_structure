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

void push(STACK *s , void *data , Type datatype){
    NODE *temp = create_node();
    temp->data_type = datatype;

    if(datatype == INT){
        temp->data = malloc(sizeof(int));
        *(int *)temp->data = *(int *)data;
    }
    else if(datatype == CHAR){
        temp->data = malloc(sizeof(char));
        *(char *)temp->data = *(char *)data;
    }
    else if(datatype == FLOAT){
        temp->data = malloc(sizeof(float));
        *(float *)temp->data = *(float *)data;
    }

    if(s->top == NULL){
        s->top = temp;
        return;
    }

    temp->next = s->top;
    s->top = temp;

}

void *pop(STACK *s , void *data){
    if(s->top == NULL){
        return NULL;
    }
    NODE *temp = s->top;
    
    data = temp->data;
    
    s->top = temp->next;
    
    free(temp);

    return data;
}

bool is_empty(const STACK *s){
    if(s->top == NULL){
        return 1;
    }
    return 0;
}

void *peek(const STACK *s){
    if(is_empty(s)){
        printf("stack is empty.\n");
        return NULL;
    }
    
    void *value = s->top;

    return value;

}

