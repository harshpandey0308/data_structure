#include<iostream>

using namespace std;

class BBST{
    private : 
       typedef struct NODE{
            int value;
            struct NODE *left;
            struct NODE *right; 
       }NODE;

       NODE *root = NULL;
    
    public : 
        NODE *_init_tree(){
            NODE *new_ = new NODE();
            new_->left = NULL;
            new_->right = NULL;

            return new_;
        }

        int *height(NODE *current){
            if(current == NULL){
                return NULL;
            }

            int *heights = new int(0);

            if(height == NULL){
                cout<<"Invalid memory"<<'\n';
                exit(EXIT_FAILURE);
            }

            if(current->right == NULL && current->left == NULL){
                return height;
            }
            else if(current->left != NULL && current->right == NULL){
                heights = height(current->left);
            }
            else if(current->right != NULL && current->left == NULL){
                heights = height(current->right);
            }
            else{
                int height1 = height(current->left);
                if(height1 == NULL){
                    exit(EXIT_FAILURE);
                }

                int height2 = height(current->right);
                if(height2 == NULL){
                    exit(exit_failure);
                }

                if(*height1 < *height2){
                    return height2;
                }
                else{
                    return height1;
                }
            }

        }
     
        NODE *balance_insertion(NODE *current , int value){
            if(root == NULL){
               current = _init_tree();
               current->value = value;
               root = current;
               return root;
            }

            if(current == NULL){
               current = _init_tree();
               current->value = value;
               return current;
            }
            else if(current->value < value){
                current->right = balance_insertion(current->right , value);
            }
            else if(current->value > value){
                current->left = balance_insertion(current->left , value);
            }

            int *left_height = NULL;
            left_height = height(current->left);
            if(height == NULL){
                cout<<"invalid height"<<'\n';
                exit(EXIT_FAILURE);
            }

            int *right_height = NULL;
            right_height = height(current->right);
            if(right_height == NULL){
                cout<<"invalid height"<<'\n';
                exit(EXIT_FAILURE);
            }

            int balance_factor = *(left_height) - *(right_height);

            if(-2 < balance_factor < 2){
                cout<<"tree is balance";
                return current;
            }
            else{
                cout<<"tree is not balanced"<<'\n';
            }
        }
}