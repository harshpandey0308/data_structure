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
            else{
                return current;
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
    
    public : 
        void insert(int value){
            root = balance_insertion(root , value);
        }

        void inorder_tree(NODE *current){
            if(current == NULL){
                return;
            }

            inorder_tree(current->left);
            cout<<current->value<<'\n';
            inorder_tree(current->right);

        }

        void print_tree(){
            inorder_tree(root);
        }

        void destroy_tree(NODE *current){
            if(current == NULL){
                return;
            }

            destroy_tree(current->left);
            destroy_tree(current->right);

            delete current;
        }

        ~BBST(){
            destroy_tree(root);
        }
};

int main(){
    BBST b1;

    b1.insert(50);
    b1.insert(60);
    b1.insert(100);
    b1.insert(23);
    b1.insert(34);
    b1.insert(7);
    b1.insert(3);
    
    b1.print_tree();

    return 0;

}