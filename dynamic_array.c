#include<stdio.h>
#include<stdbool.h>
#include"dynamic_array.h"

void init(Dynamicarray *arr , size_t capacity){
    arr->size = 0;
    arr->capacity = capacity;

    arr->data = malloc(arr->capacity*sizeof(int));

    if(arr->data == NULL){
        perror("malloc failed.");
        exit(EXIT_FAILURE); 
    }
}

void resize(Dynamicarray *arr){
    size_t new_capacity = 2*arr->capacity;

    int *temp = realloc(arr->data , new_capacity*sizeof(*arr->data));

    if(temp == NULL){
        printf("reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
    else{
        arr->data = temp;
        arr->capacity = new_capacity;
    }
}

void insert_at(Dynamicarray *arr , size_t index , int data){
    //printf("insertion starts.\n");
    if(arr->size == arr->capacity){
        resize(arr);
    }

    if(index > arr->size){
        fprintf(stderr , "Invalid index");
        exit(EXIT_FAILURE);
    }
    else{
        if(index < arr->size){
            //printf("shifting happens.\n");
            for(size_t j= arr->size ; j>index ; --j){
                arr->data[j] = arr->data[j-1];
            }
            arr->data[index] = data;
        }
        else{
            arr->data[index] = data;
        }
        arr->size++;
    }
    

}

void pop_back(Dynamicarray *arr){
    printf("size = %zu.\n",arr->size);
    if(arr->size == 0){
        printf("the array is underflow , can't pop any element .\n");
        return;
    }

    arr->size--;
    //printf("size = %zu.\n",arr->size);
    //printf("The element is pop out of the array.\n");

}

bool get(Dynamicarray *arr , size_t index){
    if(index >= arr->size){
        printf("INVALID index.\n");
        return 0;
    }
    
    printf("%d.\n",arr->data[index]);
    return 1;
}

void destroy(Dynamicarray *arr){
    free(arr->data);
    arr->size = 0;
    arr->data = NULL;
    arr->capacity = 0;
}

int main(){
    Dynamicarray arr;

    init(&arr , 2);

    insert_at(&arr , 0 , 76);
    //printf("size : %zu.\n",arr.size);

    insert_at(&arr , 1 , 34);
    insert_at(&arr , 1 , 18);
    insert_at(&arr , 1 , 24);

    //printf("size : %zu.\n",arr.size);
    printf("capacity = %zu.\n",arr.capacity);

    get(&arr , 1);

    pop_back(&arr);

    printf("size : %zu.\n",arr.size);

    
    for(size_t i=0 ; i<arr.size ; i++){
        printf("arr[%zu] = %d.\n",i , arr.data[i]);
    }

    destroy(&arr);

}