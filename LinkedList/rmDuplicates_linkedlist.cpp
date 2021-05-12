// Given a sorted linked list, delete all duplicates such that each element appear only once.

// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    // ListNode(int x) : val(x), next(NULL) {}
};

ListNode* connectLinks(vector<int> Arr){
    ListNode* head = NULL;
    for(int i = Arr.size() - 1; i >= 0; i--){
        ListNode* temp = new ListNode;
        temp->val = Arr[i];
        temp->next = head;
        head = temp;
    }
    return head;
}

ListNode* rmDuplicates(ListNode* A){
    ListNode* prev = A;
    ListNode* curr = A->next;
    
    while(curr != NULL){
        if(prev->val == curr->val){
            prev->next = curr->next;
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }
    return A;
}

void printLinked(ListNode* n){
    while(n != NULL){
        cout<<n->val<<"->";
        n = n->next;
    }
    cout<<endl;
}

int main() {
    vector<int> arr = {0, 1, 1, 2, 3, 4, 4, 5, 10};
    ListNode* A = connectLinks(arr);
    printLinked(A);
    ListNode* noDupes = rmDuplicates(A);
    printLinked(noDupes);
    return 0;
}