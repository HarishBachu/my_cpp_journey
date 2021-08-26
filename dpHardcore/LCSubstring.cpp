//Find the length of the longest common substring between 2 strings 
//NOTE: SUBSEQUENCE IS NON-CONTIGUOUS, SUBSTRING IS CONTIGUOUS

#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int lcsLen(string A, string B, int nA, int nB) {
    int dp[nA+1][nB+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= nA; i++) {
        for(int j = 1; j <= nB; j++) {
            if(A[i] == B[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                continue;
        }
    }
    return dp[nA][nB];
}

int main() {
    string A = "abcde";
    string B = "abfce";
    cout<<lcsLen(A, B, A.size(), B.size());
    return 0;
}