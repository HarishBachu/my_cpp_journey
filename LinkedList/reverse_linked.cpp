#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* reverseLinked(ListNode* A){
    ListNode* next;
    ListNode* current = A;
    ListNode* prev = NULL;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    A = prev;
    return A;
}