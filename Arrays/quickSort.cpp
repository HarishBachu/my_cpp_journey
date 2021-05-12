#include<iostream>
#include<vector>
#include<climits>

using namespace std; 

int Partition(vector<int> &A, int start, int end){
    int pIndex = start;
    int pivot = A[end];
    int temp;
    for(int i = start; i < end - 1; i++){
        if(A[i] <= pivot){
            temp = A[i];
            A[i] = A[pIndex];
            A[pIndex] = temp;
            pIndex++;
        }
    }   
    temp = A[pIndex];
    A[pIndex] = A[end];
    A[end] = temp;
    return pIndex;
}

void QuickSort(vector<int> &A, int start, int end){

    if(start < end){
        int pIndex = Partition(A, start, end);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
}

int main(){
    vector<int> A = {7, 6, 5, 4, 3, 2, 1, 0};
    QuickSort(A, 0, A.size() - 1);
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}