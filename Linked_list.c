#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Linked_list.h"

void stack_init(STACK *s){
    s->top = NULL;
}

NODE *create_node(NODE *p){
    p = malloc(sizeof(NODE));
    p->next = NULL;
    return p;
}

bool push(STACK *s , int data){
    if(s->top == NULL){
        stack_init(s);
        s->node = create_node(s);
        s->node->data = data;
        s->node->next = NULL;
        s->top = s->node;
        return 1;
    }

}