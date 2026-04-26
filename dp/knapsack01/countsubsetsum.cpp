// Question Link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <iostream>
#include <vector>

class Solution {
  public:
    int solve(std::vector<int> &nums, int target, int n) {
        if (n == 0) {
            if (target == 0) return 1;
            return 0;
        }
        
        return solve(nums, target - nums[n-1], n-1) + solve(nums, target, n-1);
    }
    
    int perfectSum(std::vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return solve(arr, target, n);
    }
};

/**
 * Top - Down DP
 */
class Solution {
  public:
    int perfectSum(std::vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(target+1, 0));

        for (int i = 0; i <= n; ++i) dp[i][0] = 1;

        for (int i = 1; i < n+1; ++i) {
            for (int j = 0; j < target + 1; ++j) {
                if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
        }

        return dp[n][target];
    }
};