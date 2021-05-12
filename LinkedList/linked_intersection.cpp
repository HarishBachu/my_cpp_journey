#include<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {} 
};

int getLinkedLength(ListNode* head){
    int length = 0;
    while(head != NULL){
        head = head->next;
        length++;
    }
    return length;
}

ListNode* getIntersectionNode(ListNode* A, ListNode* B){

    int len_a = getLinkedLength(A);
    int len_b = getLinkedLength(B);
    int d;
    if(len_a > len_b){
        d = len_a - len_b;
        for(int i = 0; i < d; i++){
            A = A->next;
        }
    } 
    else if(len_a < len_b){
        d = len_b - len_a;
        for(int i = 0; i < d; i++){
            B = B->next;
        }
    }
    while(A!=NULL && B!=NULL){
        if(A == B)
            return A;
        A = A->next;
        B = A->next;
    }
    return nullptr;
}