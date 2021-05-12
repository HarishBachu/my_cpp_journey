#include<iostream>

using namespace std; 

class Node {
    public:
        int data;
        Node* next;
};

void printLinked(Node* n){
    while(n != NULL){
        cout<<n->data<<" ";
        n = n->next;
    }
}

void push(Node** head, int data){
    Node* new_head = new Node();
    new_head->data = data;
    new_head->next = *head;
    *head = new_head;
}

void insert_at_pos(Node* prev, int data){
    if(prev == NULL){
        cout<<"Never gonna give you up"<<endl;
        return;
    }

    Node* temp = new Node();
    temp->data = data;
    temp->next = prev->next;
    prev->next = temp;
}

void append(Node* head, int data){
    Node* temp = new Node();
    Node* end = head;
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    while(end->next != NULL){
        end = end->next;
    }
    end->next = temp;
    return;
}

int main(){

    Node* A = NULL;
    Node* B = NULL;
    Node* C = NULL;
    Node* D = NULL;

    A = new Node();
    B = new Node();
    C = new Node();
    D = new Node();

    A->data = 1;
    A->next = B;

    B->data = 2;
    B->next = C;

    C->data = 3;
    C->next = D;

    D->data = 4;
    D->next = NULL;

    insert_at_pos(C, 2);
    append(A, 100);
    push(&A, -100);

    printLinked(A);

    return 0;
}