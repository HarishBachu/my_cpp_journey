//Given an array of numbers, check if it is possible to split it into 3 subsequences of equal sum 

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool subsetSum(vector<int> nums, int sum, int n) {
    
    int dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i-1] <= j) 
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    // cout<<dp[n][sum];
    return dp[n][sum] >= 3;
}

bool canPart(vector<int> nums) {
    const int n = nums.size();
    int sum = 0;
    for(int num : nums)
        sum += num; 
    if(sum%3 != 0)
        return false;

    sum /= 3; 
    return subsetSum(nums, sum, n);

}

int main() {
    vector<int> nums = {7, 3, 2, 1, 5, 4, 8};
    cout<<canPart(nums);
    return 0;
}