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

                friend class RB_tree;
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
            if(grandparent == nullptr || current == nullptr){
                return nullptr;
            }

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
            NODE *gp = find_grandparent(current->parent);
            if(gp == nullptr){
                return;
            }

            NODE *uncle = find_uncle(current , gp); // assumming that uncle can never be nullptr during coloring

            if(current == root){
                return;
            }

            if(current->parent->color == 'B'){
                return;
            }

            current->parent->color = 'B';
            uncle->color = 'B';
            gp->color = 'R';
            
            recoloring(gp);
        }

        NODE *right_rotation(NODE *current){
            NODE *new_node = current->left;
            new_node->parent = current->parent;
            current->parent = new_node;
            current->left = new_node->right;
            new_node->right = current;
            
            return new_node;
        }

        NODE *left_rotation(NODE *current){
            NODE *new_node = current->right;
            new_node->parent = current->parent;
            current->parent = new_node;
            current->right = new_node->left;
            new_node->left = current;

            return new_node;
        }

        void swap_color(NODE *current1 , NODE *current2){
            char temp;
            temp = current1->color;
            current1->color = current2->color;
            current2->color = temp;
        }

        void rotation(NODE *current , NODE *grandparent){
            NODE *parent = current->parent;
            if(grandparent->left == parent && current == parent->left){
                grandparent = right_rotation(grandparent);
                swap_color(parent , grandparent);
            }
            else if(grandparent->left == parent && current == parent->right){
                parent = left_rotation(parent);
                grandparent = right_rotation(grandparent);

                swap_color(current , grandparent;)
            }
            else if(grandparent->right == parent && current == parent->right){
                grandparent = left_rotation(grandparent);
                swap_color(parent , grandparent);
            }
            else if(grandparent->right == parent && current == parent->left){
                parent = right_rotation(parent);
                grandparent = left_rotation(grandparent);

                swap_color(current , grandparent);
            }
        }

        NODE *insert(NODE *current , int value){
            NODE *grandparent = find_grandparent(current->parent);
            NODE *uncle = find_uncle(current , grandparent);
            
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

            if(current->color == 'R' && current->parent->color == 'B'){
                cout<<"No need to change color , tree is balanced"<<endl;
            }
            else if(current->color == 'R' && current->parent->color =='R'){
                if(uncle == nullptr || uncle->color == 'B'){
                   rotation(current);
                }
                else{
                   recoloring(current);
                }
            }
        }
}