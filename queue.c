#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enque(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;

    if(front==NULL && rear==NULL){
        front = rear = temp;
        return;
    }

    rear->next = temp;
    rear = temp ;
}

void deque(){
    if(front==NULL){
        printf("the list is empty.");
        return;
    }
    if(front ==  rear){
        struct node* temp = front;
        rear = front = NULL;
        return;
    }
    struct node* temp = front;
    front = front->next;
    free(temp);
}

int IS_empty(){
    if(front == NULL && rear == NULL){
        return 1;
    }
}

void print(){
    struct node* temp = front;
    while(temp != NULL){
        printf("\n%d",temp->data);
        temp = temp->next;
    }
}

int main(){
    printf("insert the number into the queue:\n");
    enque(5);
    enque(6);
    enque(7);
    enque(8);
    deque();
    enque(14);
    deque();
    print();
    return 0;
}