#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void merge(vector <int> &A, vector <int> &B){

    int ia = 0;
    int ib = 0;

    while(ia < A.size() && ib < B.size()){
        if(B[ib] < A[ia]){
            A.insert(A.begin() + ia, B[ib]);
            ib++;
        }
        else{
            ia++;
        }
    }

    while(ib < B.size()){
        A.push_back(B[ib]);
        ib++;
    }
}

int main(){
    vector<int> A = {0, 4};
    vector<int> B = {-2, -2, 100};
    merge(A, B);
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    return 0;
}