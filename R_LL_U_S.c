#include<stdio.h>
#include<stdlib.h>
#include"linked_list.h"
#include"stack.h"

int main(){
    int n;
    char a;
    printf("Enter the number of elements in the linked list you want:\n");
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        printf("enter the character you want to insert in the linked list:\n");
        scanf(" %c",&a);
        insert(i+1 , a);
    }
    printf("the elements in the linked list are :\n");
    print1();
    struct node* var = head;
    while(var != NULL){
        push(var->data);
        var = var->next;
    }

    while(head != NULL){
        deletion(1);
    }
    
    for(int i=0 ; i<n ; i++){
        insert(i+1 ,pop());
    }
    printf("\nthe reversed string in the linked list is:\n");
    print1();

    return 0;
}