//Minimum coins required to give change 

#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std; 

int minCoins(vector<int> coins, int sum, int n) {
    
    int dp[n+1][sum+1];

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= sum; i++)
        dp[0][i] = INT_MAX-1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(coins[i-1] <= j)
                dp[i][j] = min (1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}

int main() {

    vector<int> coins = {1, 2, 4};
    int S = 10; 
    cout<<minCoins(coins, S, coins.size());
    return 0;
}