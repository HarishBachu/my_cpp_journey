#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

void pushNode(Node** head, int val) {  
    assert(*head != NULL); 
    Node* new_head = new Node;
    new_head->val = val;
    new_head->prev = NULL;
    new_head->next = *head;
    if(*head != NULL)
        (*head)->prev = new_head;
    *head = new_head;
}

void appendNode(Node* head, int val) {
    assert(head != NULL);
    while(head->next != NULL){
        head = head->next;
    }
    Node *end = new Node;
    end->val = val;
    end->next = NULL;
    end->prev = head;
    head->next = end;
}

void insertNode(Node* head, Node* nextNode, int val) {
    
    assert(nextNode != NULL);
    while(head->next != nextNode)
        head = head->next;
    Node* newNode = new Node;
    newNode->val = val;
    head->next = newNode;
    newNode->prev = head;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

Node* connectDLL(vector<int> arr) {
    Node* head = new Node;

    head->val = arr[0];
    head->next = NULL;
    head-> prev = NULL;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node;
        temp->val = arr[i];
        temp->prev = head;
        temp->next = NULL;
        head->next = temp;
        head = temp;
    }

    while(head->prev != NULL){
        head = head->prev;
    }
    return head;
}

void printDLL(Node* dll) {
    while(dll != NULL){
        cout<<dll->val;
        if(dll->next != NULL)
            cout<<"<->";
        dll = dll->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* dll = connectDLL(arr);
    printDLL(dll);
    pushNode(&dll, 100);
    printDLL(dll);
    appendNode(dll, 404);
    printDLL(dll);
    insertNode(dll, dll->next->next->next, 69);
    printDLL(dll);
    // cout<<dll->next->val;
    return 0;
}

