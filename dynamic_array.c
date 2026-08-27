#include<stdio.h>
#include"dynamic_array.h"

void init(Dynamicarray *arr , size_t capacity){
    arr->size = 0;
    arr->capacity = capacity;

    arr->data = malloc(arr->capacity*sizeof(int));

    if(arr->data == NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
}

void insert_at(int arr[] , size_t size , size_t capacity , size_t index , int data){
    if(size == capacity){
        perror("Array is full.");
        exit(EXIT_FAILURE);
    }


    if(index > size){
        perror("Invalid index");
        exit(EXIT_FAILURE);
    }
    else{
        if(index < size){
            for(int j=size-1 ; j>=index ; j--){
                arr[j+1] = arr[j];
            }
            arr[index] = data;
        }
        else{
            arr[index] = data;
        }
        size++;
    }
    

}

int main(){
    Dynamicarray arr;

    init(&arr , 15);

    insert_at(arr.data , arr.size , arr.capacity , 0 , 76);
    insert_at(arr.data , arr.size , arr.capacity , 0 , 34);

    printf("size : %d.\n",arr.size);

    
    printf("arr[0] : %d.\n",arr.data[0]);
    printf("arr[1] : %d.\n",arr.data[1]);


}