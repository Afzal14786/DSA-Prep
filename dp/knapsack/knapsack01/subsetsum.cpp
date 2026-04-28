/**
 * We are given an array of nums and a target sum, We have to find 
 * Is there any subset exist whose sum is equal to target .
 * If yes then return true
 * else return false
 */

#include <iostream>
#include <vector>

/**
 * This is the recursive solution ...  
 */
bool solve(std::vector<int> &nums, int target, int n) {
    if (n == 0) return false;
    if (target == 0) return true;

    if (nums[n-1] > target) return solve(nums, target, n-1);
    else return solve(nums, target-nums[n-1], n-1) || solve(nums, target, n-1);
}

bool isSubSet(std::vector<int> &nums, int target) {
    int n = nums.size();
    return solve(nums, target, n);
}

/**
 * Top Down Solution 
 */

bool SubsetSum(std::vector<int> &nums, int target) {
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(target+1));
    // initializatio
    for (int i = 0; i <= n; ++i) dp[i][0] = true;

    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < target+1; ++j) {
            if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j - nums[i-1]] || dp[i-1][j];
        }
    }

    return dp[n][target];
}