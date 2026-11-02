#include<iostream>
#include<vector>

using namespace std;

class BBST{
    private : 
       typedef struct NODE{
            int value;
            int height;
            struct NODE *left;
            struct NODE *right; 
       }NODE;
    
    public : 
        NODE *root = NULL;

        NODE *_init_tree(){
            NODE *new_ = new NODE();
            new_->left = NULL;
            new_->right = NULL;
            new_->height = 0;

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

        int _height(NODE *current){
            if(current == NULL){
                return -1;
            }

            return current->height;
        }

        void height_update(NODE *current){
            int left_heights = _height(current->left);
            int right_heights = _height(current->right);

            current->height = 1 + max_height(&left_heights , &right_heights);
        }

        NODE *right_rotation(NODE *current){
            NODE *new_root = current->left;
            current->left = new_root->right;
            new_root->right = current;

            height_update(current);

            height_update(new_root);

            return new_root;
        }

        NODE *left_rotation(NODE *current){
            NODE *new_root = current->right;
            current->right = new_root->left;
            new_root->left = current;

            height_update(current);

            height_update(new_root);

            return new_root;
        }

        int balance_factor(NODE *current){
            return (_height(current->left) - _height(current->right));
        }
     
        NODE *balance_insertion(NODE *current , int value){
            int left_height = -1;
            int right_height = -1;

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

            left_height = _height(current->left);
            right_height = _height(current->right);

            current->height = 1 + max_height(&left_height , &right_height);

            int bf = balance_factor(current);

            if(bf > 1){
                if(balance_factor(current->left) >= 0){
                    current = right_rotation(current);
                }
                else{
                    current->left = left_rotation(current->left);
                    current = right_rotation(current);
                }
            }
            else if(bf < -1){
                if(balance_factor(current->right) <= 0){
                    current = left_rotation(current);
                }
                else{
                    current->right = right_rotation(current->right);
                    current = left_rotation(current);
                }
            }

            return current;
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