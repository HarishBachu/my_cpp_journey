//Given an array of numbers and a target sum, check if there is a subset of numbers which sum up to the target.
//Also return the number of subsets that sum to the target

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

bool targetSum(vector<int>nums, int target, int n) {

    bool dp[n+1][target+1];
    
    //Base Cases
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }
    
    //Choice Diagram
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            if(nums[i-1] <= j) 
                dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}

int countTargetSum(vector<int> nums, int target, int n) {

    int dp[n+1][target+1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= target; j++) {
            if(i == 0)
                dp[i][j] = 0;
            if(j == 0)
                dp[i][j] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= target; j++) {
            if(nums[i-1] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][target];
}

int main() {
    vector<int> nums = {1, 2, 3, 7, 8, 9, 10};
    int target = 11; 
    int n = nums.size();

    cout<<targetSum(nums, target, n)<<endl;
    cout<<countTargetSum(nums, target, n);
    
    return 0;
}