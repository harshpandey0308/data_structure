#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"

struct node* head = NULL;

void insert(int pos , char x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(head == NULL || pos == 1){
        temp->next = head;
        head = temp;
        return;
    }
    
    struct node* temp1 = head;
    for(int i=1 ; i<pos-1 ; i++)
    {
        temp1 = temp1->next;
        if(temp1 == NULL){
            printf("invalid position");
            return ;
        }
    }
    struct node* temp2 = temp1->next;
    temp1->next = temp;
    temp->next = temp2;
}

void deletion(int pos){
    if(head == NULL){
        printf("the list is empty");
        return ;
    }

    struct node* temp = head;
    for(int i=1 ; i<pos-1 ; i++){
        temp = temp->next;
        if(temp == NULL){
            printf("invalid position");
            return;
        }
    }
    if(pos == 1){
        struct node* _temp = head;
        head = temp->next;
        free(_temp);
        return;
    }
    struct node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

void print1(){
    struct node* temp = head;
    while(temp != NULL){
        printf("\n %c",temp->data);
        temp = temp->next;
    }
}