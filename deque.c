#include<stdio.h>
#include<stdbool.h>
#include"deque.h"

void init_deque(deque *dq){
    dq->front = 0;
    dq->size = 0;
}

bool push_front(deque *dq , int data){
     if(dq->size == CAPACITY){
        return false;
     }

     dq->front = (dq->front + CAPACITY - 1)%CAPACITY;

     dq->data[dq->front] = data;
     dq->size++;
     return true;
}

bool pop_front(deque *dq , int *data){
    if(dq->size == 0){
       return false;
    }
 
    *data = dq->data[dq->front];

    dq->front = (dq->front + 1)%CAPACITY;

    dq->size--;
    return true;
    
}

