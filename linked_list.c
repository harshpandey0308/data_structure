#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int x , int n)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    
    if(temp == NULL){
        printf("memory allocation is not successful.");
    }
    temp->data = x;
    temp->next = NULL;
    if(n == 1){
        temp->next = head;
        head = temp;
        return ;
    }
    
    struct node *current = head;
    for(int i=0 ; i<n-2 && current != NULL ; i++)
    {
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;

    if(current == NULL)
    {
        printf("position is out of range.");
        free(temp);
        return;
    }
}

void print()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }
    printf("\n");

}

int main(){
    int y , n , size;
    printf("enter the number of elements in linked list:\n");
    scanf("%d",&size);

    for(int i=0 ; i<size ; i++)
    {
        printf("enter the value and position to insert:\n");
        scanf("%d%d",&y,&n);
        insert(y , n);
        printf("the linked list is:\n");
        print();
    }
    return 0;
}