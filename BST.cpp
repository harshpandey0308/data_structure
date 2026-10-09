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

        bool deletion(NODE *current , int target){
            if(current == NULL){
                cout<<"deletion is stopped , tree is empty";
                return false;
            }

            NODE *parent = NULL;
            while(current != NULL){

                if(current->value == target && current->left == NULL && current->right == NULL){
                  delete current;
                  current = NULL;
                  if(target < parent->value){
                    parent->left = NULL;
                  }
                  else{
                    parent->right = NULL;
                  }
                  cout<<"deletion completed"<<endl;
                  return true;
                }
                else if(current->value < target){
                    parent = current;
                    current = current->right;
                }
                else{
                    parent = current;
                    current = current->left;
                }
            }

            return false;
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
    b1.insert(b1.root , 7);
    b1.insert(b1.root , 34);
    b1.insert(b1.root , 4);

    b1.print(b1.root);

    b1.search(b1.root , 7);
    b1.search(b1.root , 34);
    b1.search(b1.root , 23);
    b1.search(b1.root , 10);


    b1.deletion(b1.root , 34);

    b1.print(b1.root);

    return 0;
}