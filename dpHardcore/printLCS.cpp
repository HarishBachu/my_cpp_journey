//Print the longest common subsequence between 2 strings 

#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

vector<vector<int>> LCSLen(string A, string B, int nA, int nB) {

    vector<vector<int>> dp(nA+1, vector<int>(nB+1, 0));

    for(int i = 1; i <= nA; i++) {
        for(int j = 1; j <= nB; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp;
}

string printLCS(string A, string B) {
    
    int nA = A.size();
    int nB = B.size();

    vector<vector<int>> dp = LCSLen(A, B, nA, nB);
    string res = "";
    while(nA != 0 || nB != 0) {
        if(A[nA-1] == B[nB-1]) {
            res.insert(0, 1, A[nA-1]);
            nA--;
            nB--; 
        } 
        else {
            if(dp[nA-1][nB] > dp[nA][nB-1])
                nA--;
            else 
                nB--; 
        }
    }
    return res;
}

int main() {
    string A = "abcddefg";
    string B = "abddfgg";
    cout<<printLCS(A, B);
    return 0;
}