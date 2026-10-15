#include<iostream>

using namespace std;

class BST{
    private : 
        struct NODE{
            int value;
            struct NODE *left;
            struct NODE *right;
        };

        

    public : 
        NODE *root = NULL;

        NODE *create_node(){
            NODE *new_node = new NODE;
            new_node->value = 0;
            new_node->left = NULL;
            new_node->right = NULL;

            return new_node;
        }

        void insert(NODE *current , int target){
            if(current == NULL){
                root = create_node();
                root->value = target;

                return;
            }

            NODE *parent = NULL;

            while(current != NULL){
                parent = current;
                if(current->value < target){
                    current = current->right;
                }
                else{
                    current = current->left;
                }
            }

            NODE *new_node = create_node();
            new_node->value = target;

            if(target > parent->value){
                parent->right = new_node;
            }
            else{
                parent->left = new_node;
            }
        }

        bool search(NODE *current , int target){
            if(current == NULL){
                cout<<"No elements in the tree"<<endl;
                return false;
            }

            if(current->value == target){
                cout<<"target found"<<'\n';
                return true;
            }
            else if(current->value > target){
                return search(current->left , target);
            }
            else if(current->value < target){
                return search(current->right , target);
            }
            else{
                cout<<"target not found"<<'\n';
                return false;
            }
        }

        NODE *inorder_successor(NODE *current){
            if(current == NULL){
                cout<<"tree is empty"<<'\n';
                return NULL;
            }

            NODE *temp = current->right;
            if(temp == NULL){
                return NULL;
            }
            while(temp->left != NULL){
                temp = temp->left;
            }
            
            return temp;
        }

        NODE *inorder_predecessor(NODE* current){
            if(current == NULL){
                return current;
            }

            NODE *temp = current->left;
            if(temp == NULL){
                return temp;
            }
            while(temp->right != NULL){
                temp = temp->right;
            }

            return temp;
        }

        NODE *delete_(NODE *current , int target){
            if(current == NULL){
                return current;
            }

            if(current->value == target){
                if(current->left == NULL && current->right == NULL){
                    delete current;
                    return NULL;
                }
                else if(current->left != NULL && current->right == NULL){
                    NODE *temp = current->left;
                    delete current;
                    return temp;
                }
                else if(current->left == NULL && current->right != NULL){
                    NODE *temp = current->right;
                    delete current;
                    return temp;
                }
                else{
                    NODE *succ = inorder_successor(current);
                    current->value = succ->value;
                    current->right = delete_(current->right , succ->value);       
                    return current;
                }
            }
            else if(current->value < target){
                current->right = delete_(current->right , target);
                return current;
            }
            else{
                current->left = delete_(current->left , target);
                return current;
            }

        }
        

        void print(NODE *temp){
            if(temp == NULL){
                return;
            }

            print(temp->left);
            cout<<temp->value<<'\n';
            print(temp->right);
            
        }

        void destroy(NODE *current){
            if(current == NULL){
                return;
            }

            destroy(current->left);
            destroy(current->right);

            delete current;
        
        }

        ~BST(){
            destroy(root);
        }
};

int main(){
    BST b1;

    b1.insert(b1.root , 8);
    b1.insert(b1.root , 10);
    b1.insert(b1.root , 9);
    b1.insert(b1.root , 7);
    b1.insert(b1.root , 34);
    b1.insert(b1.root , 4);

    b1.print(b1.root);

    b1.search(b1.root , 7);
    b1.search(b1.root , 34);
    b1.search(b1.root , 23);
    b1.search(b1.root , 10);

    b1.root = b1.delete_(b1.root , 10);
    b1.root = b1.delete_(b1.root , 4);
    b1.root = b1.delete_(b1.root , 34);

    int successor = b1.inorder_successor(b1.root)->value;
    int predecessor = b1.inorder_predecessor(b1.root)->value;
    cout<<"successor = "<<successor<<'\n';
    cout<<"predecessor = "<<predecessor<<'\n';

    b1.print(b1.root);

    return 0;
}