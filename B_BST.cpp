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
            if(left_height == NULL){
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