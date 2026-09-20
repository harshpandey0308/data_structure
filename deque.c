#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<stdbool.h>
#include"deque.h"

void _init_deque(deque *dq){
     dq->front = 0;
     dq->size = 0;
}

bool push_front(deque *dq , int data){
    if(dq->size == CAPACITY){
        fprintf(stderr , "queue is full.\n");
        return false;
    }

    dq->front = (dq->front + CAPACITY - 1)%CAPACITY;
    dq->data[dq->front] = data;

    dq->size++;

    return true;
}

bool pop_front(deque *dq){
    if(dq->size == 0){
        fprintf(stderr , "queue is underflow.\n");
        return false;
    }

    dq->front = (dq->front + 1)%CAPACITY;

    dq->size--;

    return true;
}

bool push_rear(deque *dq , int data){
    if(dq->size == CAPACITY){
        fprintf(stderr , "queue is full.\n");
        return false;
    }

    size_t rear =  (dq->front + dq->size)%CAPACITY;

    dq->data[rear] = data;
    dq->size++;

    return true;
}

bool pop_rear(deque *dq){
    if(dq->size == 0){
        fprintf(stderr , "underflow.\n");
        return false;
    }

    size_t rear = (dq->front + dq->size - 1)%CAPACITY;

    dq->size--;

    return true;
}

void print_que(deque *dq){
    if(dq->size == 0){
        fprintf(stderr , "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0 ; i <dq->size ; i++){
        printf("deque element : %d.\n",dq->data[(dq->front + i)%CAPACITY]);
    }
}

int main(){
    deque dq;

    _init_deque(&dq);

    push_rear(&dq , 45);
    push_front(&dq , 34);

    push_rear(&dq , 23);
    push_front(&dq , 98);

    push_rear(&dq , 37);
    push_front(&dq , 123);

    pop_rear(&dq);
    pop_front(&dq);

    print_que(&dq);

    return 0;
}