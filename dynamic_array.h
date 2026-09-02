#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdlib.h>
#include<stdbool.h>

typedef struct Dynamicarray{
    int *data;
    size_t size;
    size_t capacity;
}Dynamicarray;

void init(Dynamicarray *arr , size_t capacity);

void insert_at(Dynamicarray *arr, size_t index , int data);

void pop_back(Dynamicarray *arr);

bool get(Dynamicarray *arr , size_t index);

void resize(Dynamicarray *arr);

void destroy(Dynamicarray *arr);

#endif