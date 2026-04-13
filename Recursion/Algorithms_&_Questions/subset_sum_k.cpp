// Question Link : https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?interviewProblemRedirection=true&search=Subset%20Sum

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool generateSubsets(int idx, int K, std::vector<int> &nums, int n, int currSum) {
    if (n == idx) {
        if (K == currSum) return true;
        return false;
    }

    currSum += nums[idx];
    if (generateSubsets(idx+1, K, nums, n, currSum)) return true;
    currSum -= nums[idx];

    if (generateSubsets(idx+1, K, nums, n, currSum)) return true;

    return false;
}

/**
 * Optimize Solution
 * Time Complexity : O(N * K)
 * Space Complexity : O(N * K)
 */

bool solve(int idx, int target, std::vector<int> &nums, std::vector<std::vector<int>> &dp) {
    if (target == 0) return true;
    if (idx == 0) return (nums[0] == target);

    if (dp[idx][target] != -1) return dp[idx][target];

    bool notPick = solve(idx - 1, target, nums, dp);
    bool pick = false;

    if (nums[idx] <= target) {
        pick = solve(idx - 1, target - nums[idx], nums, dp);
    }

    return dp[idx][target] = (pick || notPick);
}

bool subsetSumToK2(int n, int k, std::vector<int> &arr) {
    // Write your code here.
    std::vector<std::vector<int>> dp(n, std::vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}


/**
 * Better Solution With 
 * Space Complexity : O(N)
 */

bool subsetSumToK(int n, int k, std::vector<int> &arr) {
    // Write your code here.
    std::vector<bool> pre(k+1, false);
    pre[0] = true;

    if (arr[0] <= k) pre[arr[0]] = true;

    for (int i = 1; i < n; ++i) {
        std::vector<bool> curr(k+1, false);
        curr[0] = true;

        for (int target = 1; target <= k; ++target) {
            bool notPick = pre[target];
            bool pick = false;
            if (arr[i] <= target) {
                pick = pre[target - arr[i]];
            }
            curr[target] = pick || notPick;
        }
        pre = curr;
    }

    return pre[k];
}

// bool subsetSumToK(int n, int k, std::vector<int> &arr) {
    // Write your code here.
//     return generateSubsets(0, k, arr, n, 0);
// }