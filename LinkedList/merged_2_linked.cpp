#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    // ListNode(int x): val(x), next(NULL) {}
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

void printLinked(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<"EOL";
    cout<<endl;
}

void MoveNode(ListNode** dest, ListNode** src){

    ListNode* newNode = *src;
    assert(newNode != NULL);
    *src = newNode->next;
    newNode->next = *dest;
    *dest = newNode;
}

ListNode* mergeSort(ListNode* s1, ListNode*s2){

    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;

    while(1){
        if(s1 == NULL){
            tail->next = s2;
            break;
        }
        else if(s2 == NULL){
            tail->next = s1;
            break;
        }
        if(s1->val <= s2->val){
            MoveNode(&(tail->next), &s1);
        }
        else{
            MoveNode(&(tail->next), &s2);
        }
        tail = tail->next;
    }
    return dummy.next;
}

int main(){
    vector<int> arr1 = {0, 2, 3, 6, 7, 10};
    vector<int> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* linked1 = connectLinks(arr1);
    ListNode* linked2 = connectLinks(arr2);
    ListNode* merged = mergeSort(linked1, linked2);
    printLinked(merged);
    return 0;
}