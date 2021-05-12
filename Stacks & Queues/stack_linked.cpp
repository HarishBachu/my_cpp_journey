//Linked List implementation of Stacks

#include<iostream>
#include<cassert>

using namespace std;

struct Node {
    int val;
    Node* next;
};

void push(Node** head, int val) {
    // cout<<val<<endl;
    if((*head)->val != NULL){
        Node* temp = new Node;
        temp->val = val;
        temp->next = *head;
        *head = temp;
    }
    else{
        (*head)->val = val;
        (*head)->next = NULL;
    }
    // return head;
}

void pop(Node** head) {
    if(*head == NULL){
        cout<<"Nothing to pop"<<endl;
    }
    else{
        *head = (*head)->next;
    }
}

void printLinkedStack(Node* stack){             //This is illegal but you know, so we can see that the stack works properly atleast xD
    assert(stack != NULL);
    while(stack != NULL){
        cout<<stack->val;
        if(stack->next != NULL)
            cout<<"->";
        stack = stack->next;
    }
    cout<<endl;
}

int main() {
    Node* stack = new Node;
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printLinkedStack(stack);
    pop(&stack);
    printLinkedStack(stack);
    return 0;
}