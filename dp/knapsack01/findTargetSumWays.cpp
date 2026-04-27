// Question Link : https://leetcode.com/problems/target-sum/
// Question Link : https://www.geeksforgeeks.org/problems/target-sum-1626326450/1
// Question Link : https://www.naukri.com/code360/problems/target-sum_4127362?leftPanelTabValue=SUBMISSION

#include <iostream>
#include <vector>

/**
 * Recursive Solution
 */
class Solution {
public:
    int count(int idx, int currSum, int T, std::vector<int>& nums) {
        int n = nums.size();
        if (n == idx) return (currSum == T) ? 1 : 0;

        // now which one to include and not incldue
        // if the condition satisfy then we have choise 
        // either to choose or not choose 
        if (nums[idx] + currSum <= T) return count(idx+1, currSum + nums[idx], T, nums) + count(idx+1, currSum, T, nums);
        // if not satisfy then we have only one choise, not to choose 
        else return count(idx+1, currSum, T, nums);
    }

    int findTargetSumWays(std::vector<int>& nums, int target) {
        int sum  = 0, n = nums.size();
        for (int x : nums) sum += x;

        if ((sum + target) % 2 != 0 || sum < target) return 0;
        int T = (sum + target) / 2;

        return count(0, 0, T, nums);
    }
};

/**
 * Memoization Code 
 */

class Memoization {
public:
    int count(int idx, int currSum, int T, std::vector<int>& nums, std::vector<std::vector<int>>& dp) {
        int n = nums.size();
        if (n == idx) return (currSum == T) ? 1 : 0;

        // check if we have already solution 
        if (dp[idx][currSum] != -1) return dp[idx][currSum];

        // means solution is not in the dp
        // so we have choise to include or exclude
        // if we are including then

        if (nums[idx] + currSum <= T) {
            // means we have choice of include or exclude 
            return dp[idx][currSum] = count(idx+1, currSum + nums[idx], T, nums, dp) + count(idx+1, currSum, T, nums, dp);
        } else {
            // we don't have any choice means exclude
            return dp[idx][currSum] = count(idx+1, currSum, T, nums, dp);
        }
    }

    int findTargetSumWays(std::vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for (int x : nums) sum += x;

        if ((sum + target) % 2 != 0 || sum < target) return 0;

        int T = (sum + target) / 2;
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(T+1, -1));

        return count(0, 0, T, nums, dp);
    }
};

/**
 * Top Down Approach
 */

class TopDown {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        for (int x : nums) sum += x;

        if ((sum + abs(target)) % 2 != 0 || sum < abs(target)) return 0;
        int T = (sum + abs(target)) / 2;

        std::vector<std::vector<int>> dp(n+1, std::vector<int>(T+1));
        dp[0][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= T; ++j) {
                dp[i][j] = dp[i-1][j];
                if (nums[i-1] <= j) dp[i][j] += dp[i-1][j - nums[i-1]];
            }
        }

        return dp[n][T];
    }
};

int main() {
    std::vector<int> nums = {1,1,1,1,1};
    int target = 3;
    Memoization s;
    std::cout << s.findTargetSumWays(nums, target) << std::endl;
    return 0;
}