//Return length of the longest common subsequence between 2 strings; 

#include<iostream>
#include<cstring>
#include<string>
#include<vector>

using namespace std; 

int LCSLen(string A, string B, int nA, int nB) {
    
    int dp[nA+1][nB+1]; 
    memset(dp, 0, sizeof(dp)); 

    for(int i = 1; i <= nA; i++) {
        for(int j = 1; j <= nB; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1]; 
            else
                dp[i][j] = max(dp[i][j-1], max(dp[i-1][j-1], dp[i-1][j]));
        }
    }
    return dp[nA][nB];
}

int main() {
    string A = "abcde";
    string B = "cdeab";

    cout<<LCSLen(A, B, A.size(), B.size());
    return 0;
}