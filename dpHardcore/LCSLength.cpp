// Find the length of the longest subsequence present in 2 given sequences preserving the order of sequences. 

#include<iostream>
#include<string>

using namespace std;

int LCSLength(string A, string B, int m, int n) {
    if(m == 0 || n == 0)
        return 0;
    
    if(A[m-1] == B[n-1])
        return LCSLength(A, B, m-1, n-1) + 1;
    
    return max(
        LCSLength(A, B, m, n-1), 
        LCSLength(A, B, m-1, n)
    );
}

int main() {
    string A = "ABCBDAB";
    string B = "BDCABA";
    cout<<"Length of Longest Common Subsequence: "<<LCSLength(A, B, A.size(), B.size());
}