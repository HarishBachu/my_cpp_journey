//Find the minimum subset sum difference from partitioning the sequence into 2 subsets

#include<iostream>
#include<vector>
#include<cstring>
#include<climits>

using namespace std;

int subsetSum(vector<int> nums, int sum) {
    const int n = nums.size();
    bool dp[n+1][sum+1];

    //Base Case entries
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            if(i == 0)
                dp[i][j] = false;
            if(j == 0)
                dp[i][j] = true;
        }
    }

    //Choice Diagram 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sum; j++) {
            if(nums[i] <= j)
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            else    
                dp[i][j] = dp[i-1][j];
        }
    }

    vector<bool> finalSum; 
    for(int i = 1; i <= sum; i++) {
        finalSum.push_back(dp[n][i]);
        // cout<<dp[n][i]<<" ";
    }
    // cout<<endl;

    const int n_ = finalSum.size(); 
    int sumChoice = INT_MAX;
    int idxChoice;
    for(int i = 1; i < n_; i++) {
        if(finalSum[i] && abs(n_/2 - i) <= sumChoice) {
            sumChoice = abs(n_/2 - i);
            idxChoice = i;
        }
            
    }
    // cout<<idxChoice<<" "<<sum<<endl;
    return abs(2*idxChoice - sum);
}

int minSubsetSumDiff(vector<int> nums) {
    int s = 0;
    for(int num : nums)
        s += num; 
    return subsetSum(nums, s);
}

int main() {
    vector<int> nums = {1, 1, 2, 3};
    cout<<minSubsetSumDiff(nums);
    return 0;
}