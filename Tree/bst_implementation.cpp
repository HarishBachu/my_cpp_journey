//Implementation of a Binary Search Tree 

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

class Tree {
    private:
        
        Node* root;
    
    public:
    
        Tree(){
            root = NULL;
        }

        bool isEmpty(){
            if(root == NULL)
                return true;
            return false;
        }
        void insert(int val) {
            Node* p = new Node;
            Node* parent = NULL;
            p->val = val;
            p->right = NULL;
            p->left = NULL;

            if(isEmpty()){
                root = p;
            }
            else{
                Node* ptr;
                ptr = root;
                while(ptr != NULL){
                    parent = ptr;
                    if(val > ptr->val)
                        ptr = ptr->right;
                    else   
                        ptr = ptr->left;
                }
                if(val < parent->val)   
                    parent->left = p;
                else    
                    parent->right = p;
            }
        }

};

int main() {
    return 0;
}