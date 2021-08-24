//Count How many ways we can divide a sequence into 2 sequences of equal sum 

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int subsetSum(vector<int> nums, int sum, int n) {

    int dp[n+1][sum+1];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++) {
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum]/2;
}

int equalSum(vector<int> nums, int n) {

    int s = 0;
    for(int num : nums)
        s += num; 
    if(s%2 != 0)
        return 0;
    return subsetSum(nums, s/2, n);
}

int main() {
    vector<int> nums = {1, 5, 5, 11};
    cout<<equalSum(nums, nums.size());
    return 0;
}