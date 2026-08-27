#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>

typedef struct Dynamicarray{
    int *data;
    size_t size;
    size_t capacity;
}Dynamicarray;

void init(Dynamicarray *arr , size_t capacity);

void insert_at(int arr[] , size_t size , size_t capacity , size_t index , int data);

#endif