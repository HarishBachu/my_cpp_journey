// Given a Linked List A consisting of N nodes.

// The Linked List is binary i.e data values in the linked list nodes consist of only 0's and 1's.

// You need to sort the linked list and return the new linked list.

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

ListNode* sort(ListNode* A){
    int z = 0, o = 0;
    ListNode* temp = A;

    while(temp != NULL){
        if(temp->val==0)
            z++;
        else 
            o++;
        temp = temp -> next;
    }
    temp = A;
    while(A != NULL){
        if(z > 0){
            A -> val = 0;
            z--;
        }
        else{
            A -> val = 1;
        }
        A = A -> next;
    }
    return temp;
}

void printLinked(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"EOL";
    cout<<endl;
}

int main(){
    vector<int> arr = {1, 0, 0, 1};
    ListNode* l = connectLinks(arr);
    printLinked(l);
    ListNode* l_sort = sort(l);
    printLinked(l_sort);
    return 0;
}