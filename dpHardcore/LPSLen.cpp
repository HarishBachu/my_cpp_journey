//Find the length of the longest palindromic subsequence 

#include<iostream>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

int LCSLen(string A, string B, int nA, int nB) {
    int dp[nA+1][nB+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= nA; i++) {
        for(int j = 1; j <= nB; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[nA][nB];
}

int PalindromeLen(string A) {
    int n = A.size();
    string A_rev = string (A.rbegin(), A.rend());

    return LCSLen(A, A_rev, n, n);
}

int main() {
    string A = "axbcybza";
    cout<<PalindromeLen(A);
    return 0; 
}