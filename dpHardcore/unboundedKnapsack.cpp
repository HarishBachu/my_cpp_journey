//Unbounded Knapsack Problem 

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int unBoundedKnapsack(vector<int> val, vector<int> wt, int W, int n) {
    
    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int j = 0; j <= W; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(wt[i-1] <= j) 
                dp[i][j] = max(
                    val[i-1] + dp[i][j-wt[i-1]],
                    dp[i-1][j]
                );
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int W = 8;
    cout<<unBoundedKnapsack(val, wt, W, val.size());
    return 0;
}