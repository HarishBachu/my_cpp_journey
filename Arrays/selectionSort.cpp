#include<iostream>
#include<vector>

using namespace std;

void SelectionSort(vector<int> &A, int n){

    for(int i = 0; i < n - 1; i++){
        
        int iMin = i;
        
        for(int j = i + 1; j < n; j++){

            if(A[j] < A[iMin]){
                iMin = j;
            }
        }
        int temp = A[i];
        A[i] = A[iMin];
        A[iMin] = temp;
    }
}

int main(){

    vector<int> A = {2, 7, 4, 1, 5, 3};
    SelectionSort(A, A.size());
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}