//Remove BST keys outside given range 

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Node {
    int key;
    struct Node* left;
    struct Node* right; 
};

Node* newNode(int key) {
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int key) {
    if(root == NULL)
        return newNode(key); 
    if(root->key < key)
        root->right = insert(root->right, key);
    else 
        root->left = insert(root->left, key);
    return root;
}

void inorder(Node* root) {
    if(root == NULL)
        return; 
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

Node* RangeTrimming(Node* root, pair<int, int> range) {
    if(root == NULL)
        return NULL; 
    
    root->left = RangeTrimming(root->left, range);
    root->right = RangeTrimming(root->right, range); 

    int min = range.first, max = range.second;

    if(root->key < min) {
        Node* rSubTree = root->right;
        delete root;
        return rSubTree;
    }

    if(root->key > max) {
        Node* lSubTree = root->left;
        delete root;
        return lSubTree;
    }
    return root;
}

int main() {

    Node* root = NULL;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout<<"Before Range Trimming: ";
    inorder(root);
    cout<<endl;
    root = RangeTrimming(root, make_pair(-10, 13));
    cout<<"After Range Trimming: ";
    inorder(root); 
    return 0;
}