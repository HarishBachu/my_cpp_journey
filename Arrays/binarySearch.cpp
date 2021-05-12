#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int BinarySearch(vector<int> A, int elem, int start, int end){
    int index;
    int mid = (start + end)/2;
    if(start >= end){
        index = -1;
    }
    if(elem == A[mid]){
        index = mid;
    }
    else if(elem < A[mid]){
        end = mid;
        index = BinarySearch(A, elem, start, end);
    }
    else if(elem > A[mid]){
        start = mid;
        index = BinarySearch(A, elem, start, end);
    }
    return index;
}


int main(){
    //Array has to be sorted
    vector<int> A = {4,2,5,32,8,3,1,7,9,0};    
    int elem = 8;
    sort(A.begin(), A.end());
    cout<<"Sorted Array: "<<endl;
    for(int i = 0; i < A.size(); i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"Requested Element found at index: "<<BinarySearch(A, elem, 0, A.size() - 1);
    return 0;
}