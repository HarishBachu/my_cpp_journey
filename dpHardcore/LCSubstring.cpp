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

    int maxVal = 0; 

    for(int i = 1; i <= nA; i++) {
        for(int j = 1; j <= nB; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                maxVal = max(maxVal, dp[i][j]);
            }

            else
                dp[i][j] = 0;
        }
    }
    // return dp[nA][nB];
    return maxVal;
}

int main() {
    string A = "abcdf";
    string B = "abfdg";
    cout<<lcsLen(A, B, A.size(), B.size());
    return 0;
}