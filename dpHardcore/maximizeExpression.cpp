//Given a vector A (more than 4 elements), maximize the expression 
//A[s] - A[r] + A[q] - A[p]  (s > r > q > p)

#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std; 

int maximize(vector<int> A) {
    int n = A.size();
    vector<int> stage1 (n+1, INT_MIN);
    vector<int> stage2 (n, INT_MIN);
    vector<int> stage3 (n-1, INT_MIN);
    vector<int> stage4 (n-2, INT_MIN);

    for(int i = n-1; i >= 0; i--)
        stage1[i] = max(stage1[i+1], A[i]);

    for(int i = n-2; i >= 0; i--)
        stage2[i] = max(stage2[i+1], stage1[i] - A[i]);

    for(int i = n-3; i >= 0; i--)
        stage3[i] = max(stage3[i+1], stage2[i] + A[i]);
    
    for(int i = n-4; i>= 0; i--)
        stage4[i] = max(stage4[i+1], stage3[i] - A[i]);

    return stage4[0];
    
}

int main() { 
    vector<int> A = {3, 9, 10, 1, 30, 40};
    cout<<maximize(A);
    return 0;
}