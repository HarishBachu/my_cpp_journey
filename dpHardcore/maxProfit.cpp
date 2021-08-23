//Given current and future values of a stock, find the maximum profit you can make by buying any number of these stocks, with a fixed budget. 

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int maxProfit(int savings, vector<int> currPrices, vector<int> futPrices, int n, vector<vector<int>> memo) {
    //Base Case
    if(savings == 0 || n == 0)
        return 0;                   
    
    //Choice Diagram

    if(memo[n-1][savings] != -1)
        return memo[n-1][savings];

    if(currPrices[n-1] <= savings) {
        memo[n-1][savings] = max(
            futPrices[n-1] - currPrices[n-1] + maxProfit(savings - currPrices[n-1], currPrices, futPrices, n-1, memo), 
            maxProfit(savings, currPrices, futPrices, n-1, memo)
        );
        return memo[n-1][savings];
    }
    memo[n-1][savings] = maxProfit(savings, currPrices, futPrices, n-1, memo);
    return memo[n-1][savings];
}

int maxProfitTopDown(int savings, vector<int> currPrices, vector<int> futPrices, int n) {
    int dp[n+1][savings+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= savings; j++){
            if(i==0 || j==0) 
                dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= savings; j++) {
            if(currPrices[i-1] <= j)
                dp[i][j] = max(futPrices[i-1] - currPrices[i-1] + dp[i-1][j-currPrices[i-1]], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][savings];
}

int main() {
    int n = 5;
    int savings = 250;
    vector<int> currPrices = {175, 133, 109, 210, 97};
    vector<int> futPrices = {200, 125, 128, 228, 133};
    vector<vector<int>> memo(n+1, vector<int>(savings+1, -1));
    int profit = maxProfit(savings, currPrices, futPrices, n, memo);
    int profit2 = maxProfitTopDown(savings, currPrices, futPrices, n);
    cout<<profit;
    cout<<"\n"<<profit2;
    return 0; 
}