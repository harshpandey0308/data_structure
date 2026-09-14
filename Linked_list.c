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
    temp->data = data;
    temp->data_type = datatype;
    
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
    
    if(temp->data_type == INT){
        int *val = data;
        free(temp);
        return val;
    }
    else if(temp->data_type == CHAR){
        char *val = data;
        free(temp);
        return val;
    }
    else if(temp->data_type == FLOAT){
        float *val = data;
        free(temp);
        return val;
    }
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
    if(s->top->data_type == INT){
        int *value = s->top->data;
        return value;
    }
    else if(s->top->data_type == CHAR){
        char *value = s->top->data;
        return value;
    }
    else if(s->top->data_type == FLOAT){
        float *value = s->top->data;
        return value;     
    }

}

