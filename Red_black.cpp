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
        };

        public:
            NODE(int val) : parent(nullptr) , value(val) , left(nullptr) , right(nullptr) , color('R'){}

        NODE *root = nullptr;

    public:
        NODE *find_color(NODE *current){
            NODE *temp = root;
            while(temp->next != current){
                temp = temp->next;
            }

            return temp;
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

            
            if(current->color == 'R' && current->parent->color == 'R'){
                if(current->parent->parent->righ)
            }
        }
}