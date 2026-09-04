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
        s->node = temp;
        s->top = temp;
        return;
    }

    temp->next = s->node;
    s->node = temp;
    s->top = temp;

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

int main(){
    STACK s;

    stack_init(&s);

    int arr[] = {4 , 5 , 23 , 90 , 34};

    for(int i=0 ; i<5 ; i++){
        push(&s , arr[i]);
    }

    NODE *temp = s.top;
    while(temp != NULL){
        printf("NODE -> %d.\n",temp->data);
        temp = temp->next;
    }

    int value = peek(&s);
    printf("value at the top is %d.\n",value);

    return 0;
}