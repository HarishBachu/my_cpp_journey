//Print length of Shortest common supersequence

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


int SCSLen(string A, string B) {
    int nA = A.size(), nB = B.size();
    int lcslen = LCSLen(A, B, nA, nB); 

    return nA + nB - lcslen;
}

int main() {
    string A = "AGGTAB";
    string B = "AXGXTXB";
    cout<<SCSLen(A, B);
    return 0;
}