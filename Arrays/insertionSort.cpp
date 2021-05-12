#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void InsertionSort(vector<int> &A, int n){
    for(int i = 1; i < n; i++){
        int val = A[i];
        int j;
        for(j = i; j > 0; j--){
            if(A[j-1] > val){
                A[j] = A[j-1];
            }
            else{
                break;
            }
        }
        A[j] = val;
    }
}


int main(){
    vector<int> A = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, INT_MIN, INT_MAX};
    InsertionSort(A, A.size());
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}