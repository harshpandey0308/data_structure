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
        root;
    }
    
    else if(root->data < x){
        root->right = insert(root->right , x);
    }
    else{
        root->left = insert(root->left , x);
    }
    return root;
}

void delete(struct node* root , int x){
    if(root == NULL){
        return;
    }
    else if(root->data == x){
        
    }
}
