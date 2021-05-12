//Replace every element with the greatest element on the right side.

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std; 

void repElems(vector<int> &arr) {
    int i;
    int rep = -1;
    for(i = arr.size() - 1; i >= 0; i--) {
        if(arr[i] > rep)
            swap(rep, arr[i]);
        else    
            arr[i] = rep;
    }
}

void printArr(vector<int> arr) {
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    cout<<"Before: ";
    printArr(arr);
    repElems(arr);
    cout<<"After: ";
    printArr(arr);
    return 0;
}