#include<iostream>

using namespace std;

class RB_tree{
    private:
        class NODE{
            NODE *parent;
            int value;
            NODE *left;
            NODE *right;
            char color;

            public:
                NODE(int val) : parent(nullptr) , value(val) , left(nullptr) , right(nullptr) , color('R'){}
        };

        
        NODE *root = nullptr;

    public:
        NODE *find_grandparent(NODE *parent){
            if(parent == nullptr){
                return nullptr;
            }

            return parent->parent;
        }

        NODE *find_uncle(NODE *current , NODE *grandparent){
            if(grandparent->right == current->parent){
                if(grandparent->left == nullptr){
                    return nullptr;
                }
                
                return grandparent->left;
            }
            else{
                if(grandparent->right == nullptr){
                    return nullptr;
                }
                return grandparent->right;
            }
        }

        void recoloring(NODE *current){
            if(current == root){
                return;
            }
            NODE *uncle = find_uncle(current , current->parent->parent);
            current->parent->color = 'B';
            uncle->color = 'B';
            
            recoloring(current->parent);
        }

        NODE *right_rotation(NODE *current){
            NODE *new_node = current->left;
            current->left = new_node->left;
            
        }

        NODE *rotation(NODE *current , NODE *grandparent){
            NODE *parent = current->parent;
            if(grandparent->left == parent && current == parent->left){
                // LL CASE
                
            }
            else if(grandparent->left == parent && current == parent->right){
                //L-R case
            }
            else if(grandparent->right == parent && current == parent->right){
                // RR case
            }
            else if(grandparent->right == parent && current == parent->left){
                // R-L case
            }


        }

        NODE *insert(NODE *current , int value){
            if(current == nullptr){
                current = new NODE(value);
                if(current == root){
                    current->color = 'B';
                }
                return current;
            }
            else if(current->value < value){
                current->right = insert(current->right , value);
                current->right->parent = current;
            }
            else if(current->value > value){
                current->left = insert(current->left , value);
                current->left->parent = current;
            }

            
            NODE *grandparent = find_grandparent(current->parent);
            NODE *uncle = find_uncle(current , grandparent);

            if(current->color == 'R' && current->parent->color == 'B'){
                cout<<"No need to change color , tree is balanced"<<endl;
            }
            else if(current->color == 'R' && current->parent->color =='R'){
                if(uncle->color == 'R'){
                   recoloring(current);
                }
                if(uncle->color == 'B'){

                }
            }
        }
}