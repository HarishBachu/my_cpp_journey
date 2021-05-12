#include<iostream>
#include<vector>

using namespace std;

void BubbleSort(vector<int> &A, int n){

    bool sorted = false;
    int counts;
    while(!sorted){
        counts = 0;
        for(int i = 0; i < n-1; i++){
            if(A[i] > A[i+1]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                counts++;
            }
        }
        if(counts == 0){
            sorted = true;
        }
    }

}

int main(){
    vector<int> A = {2, 7, 4, 1, 5, 3};
    BubbleSort(A, A.size());
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}