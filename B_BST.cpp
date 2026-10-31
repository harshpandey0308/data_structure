#include<iostream>

using namespace std;

class BBST{
    private : 
       typedef struct NODE{
            int value;
            struct NODE *left;
            struct NODE *right; 
       }NODE;
    
    public : 
        NODE *root = NULL;

        NODE *_init_tree(){
            NODE *new_ = new NODE();
            new_->left = NULL;
            new_->right = NULL;

            return new_;
        }

        int max_height(int *height1 , int *height2){
            if(*height1 > *height2){
                return *height1;
            }
            else{
                return *height2;
            }
        }

        int height(NODE *current){
            int height1 = -1;
            int height2 = -1;
            int height = 0;

            if(current == NULL){
                height = -1;
                return height;
            }
        
            height1 = height(current->right);
            height2 = height(current->left);

            height = 1 + max_height(&height1 , &height2);
            return height;

        }

        NODE *right_rotation(NODE *current){
            NODE *new_root = current->left;
            current->left = new_root->right;
            new_root->right = current;

            return new_root;
        }

        NODE *left_rotation(NODE *current){
            NODE *new_root = current->right;
            current->right = new_root->left;
            new_root->left = current;

            return new_root;
        }
     
        NODE *balance_insertion(NODE *current , int value){
            if(root == NULL){
                root = _init_tree();
                root->value = value;
                return root;
            }

            int left_height = -1;
            int right_height = -1;

            if(current == NULL){
                current = _init_tree();
                current->value = value;
                return current;
            }
            else if(current->value < value){
                current->right = balance_insertion(current->right , value);
                right_height = height(current->right);
            }
            else if(current->value > value){
                current->left = balance_insertion(current->left , value);
                left_height = height(current->left);
            }

            int balance_factor = left_height - right_height;

            if(balance_factor <= -2 || balance_factor >= 2){
                cout<<"The tree is unbalanced"<<endl;
                if(balance_factor >= 2){
                    cout<<"left heavy unbalanced tree"<<endl;
                    current = right_rotation(current);
                }
                else{
                    cout<<"right heavy unbalanced tree"<<endl;
                    current = left_rotation(current);
                }
            }

        }
};

int main(){
    BBST b1;

    b1.balance_insertion(b1.root , 34);
    b1.balance_insertion(b1.root , 50);
    b1.balance_insertion(b1.root , 60);

    int heights = height(b1.root);
    cout<<"height of the root = "<<heights<<endl;
    return 0;
}