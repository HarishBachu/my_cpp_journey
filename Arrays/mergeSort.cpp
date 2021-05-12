#include<iostream>
#include<vector>

using namespace std;

void merge_arrays(vector<int> &orig, vector<int> &L, vector<int> &R){
    int i = 0, j = 0, k = 0;
    int nL = L.size();
    int nR = R.size();

    while(i < nL && j < nR){
        if(L[i] < R[j]){
            orig[k++] = L[i++];
        }
        else{
            orig[k++] = R[j++];
        }
    }
    while(i < nL){
        orig[k++] = L[i++];
    }
    while(j < nR){
        orig[k++] = R[j++];
    }
}

void MergeSort(vector<int> &A, int N){
        if(N < 2){
            return;
        }
        int midpoint = N/2;
        vector<int>A_left = vector<int>(A.begin(), A.begin() + N/2);
        vector<int>A_right = vector<int>(A.begin() + N/2, A.end());
        MergeSort(A_left, A_left.size());
        MergeSort(A_right, A_right.size());
        merge_arrays(A, A_left, A_right);
}


int main(){
    vector<int> A = {1,9,2,8,3,7,4,6,5,0};
    MergeSort(A, A.size());
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}