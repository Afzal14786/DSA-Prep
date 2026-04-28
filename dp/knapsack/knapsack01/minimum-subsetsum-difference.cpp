// Question Link : https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?&interviewProblemRedirection=true&attempt_status=COMPLETED
#include <iostream>
#include <vector>

class Solution {
    std::vector<int> subsetSum(std::vector<int> &nums, int range) {
        int n = nums.size();
        std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(range+1, false));

        // initialization
        for (int i = 0; i <= n; ++i) dp[i][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= range; ++j) {
                if (nums[i-1] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
        }

        // now let return the last row
        std::vector<int> ans;
        for (int j = 0; j <= range/2; ++j) {
            if (dp[n][j]) ans.push_back(j);
        }

        return ans;
    }

    int minimumSubsetSumDifference(std::vector<int> &nums) {
        int n = nums.size();
        int range = 0;
        for (int i = 0; i < n; ++i) range += nums[i];

        std::vector<int> candidate = subsetSum(nums, range);
        int mn = range;

        for (int can : candidate) {
            mn = std::min(mn, range - 2 * can);
        }

        return mn;
    }
};