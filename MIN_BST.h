#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node* insert(struct node* root , int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    }
    else if(root->data < x){
        root->right = insert(root->right , x);
    }
    else{
        root->left = insert(root->left , x);
    }
    return root;
}

struct node* find_min(struct node* root){
    if(root == NULL){
    }
    else{
        while(root->left != NULL){
            root = root->left;
        }
    }
    return root;
}

void print(struct node* root){
        if(root == NULL){
            return;
        }
        print(root->left);
        printf("%d",root->data);
        print(root->right);
}

int main(){
    int n;
    int x;
    printf("how many elements you want in the tree?\n");
    scanf("%d",&n);
    
    for(int i=0 ; i<n ; i++){
        printf("enter the element you want to insert:\n");
        scanf("%d",&x);
        root = insert(root , x);
    }
    
    printf("the elements in the tree are:\n");    
    print(root);

    printf("the minimum element in the list is:\n");
    struct node* min_node = find_min(root);
    if(min_node != NULL){
        printf("%d",min_node->data);
    }
    

    return 0;
}