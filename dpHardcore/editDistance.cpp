//Find the Levenshtein Distance between 2 strings. 
//Levenshtein distance is the number of operations required to convert one string into the other. 
//Bottom up approach.  

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int LD(string A, string B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1)); 
    // memset(dp, 0, sizeof(dp));

    for(int i = 0; i < m; i++) {
        dp[i][0] = i;
    }

    for(int j = 0; j < n; j++) {
        dp[0][j] = j;
    }

    int cost;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(A[i-1] == B[i-1])
                cost = 0;
            else
                cost = 1; 
            dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + cost);
        }
    }
    return dp[m][n];
}

int main() {
    string A = "kitten";
    string B = "sitting";
    cout<<LD(A, B);
    return 0;
}