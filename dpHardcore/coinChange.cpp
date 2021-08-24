//Find the number of ways to return change of M, given an infinite supply of coins of certain denominations. 

#include<iostream>
#include<vector>
#include<cstring>

using namespace std; 

int coinChange(vector<int> coins, int change, int n) {
    
    int dp[n+1][change+1]; 
    memset(dp, 0, sizeof(dp)); 

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= change; j++) {
            if(coins[i-1] <= j)
                dp[i][j] = max(
                    1 + dp[i][j-coins[i-1]],
                    dp[i-1][j]
                );
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][change];
}

int main() {
    vector<int> coins = {1};
    int change = 10;
    cout<<coinChange(coins, change, coins.size());
    return 0;
}