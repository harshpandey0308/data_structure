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

        void change_color(NODE *parent){
            if(parent == nullptr){
                return;
            }

            while(parent != root){

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

            if(current->color == 'R' && current->parent->color == 'R'){
                if(uncle->color == 'R'){

                }
            }
        }
}