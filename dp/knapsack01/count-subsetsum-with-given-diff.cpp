// Question Link : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <iostream>
#include <vector>

class Solution_Recusrion {
  public:
    int countSubset(int idx, int currSum, int target, std::vector<int>& nums, std::vector<std::vector<int>>& dp) {
        int n = nums.size();
        if (idx == n) return (currSum == target) ? 1 : 0;

        if (dp[idx][currSum] != -1) return dp[idx][currSum];
        int exclude = countSubset(idx+1, currSum, target, nums, dp);
        int include = 0;

        if (currSum + nums[idx] <= target) {
            include = countSubset(idx+1, currSum + nums[idx], target, nums, dp);
        }

        return dp[idx][currSum] = include + exclude;
    }

    int countPartitions(std::vector<int>& nums, int diff) {
        int sum = 0, n = nums.size();
        for (int x : nums) sum += x;

        if ((sum + diff) % 2 != 0 || sum < diff) return 0;
        int target = (sum + diff) / 2;

        std::vector<std::vector<int>> dp(n+1, std::vector<int>(target+1, -1));
        return countSubset(0, 0, target, nums, dp);
    }
};

/**
 * Top Down Approach
 */
class Solution {
  public:
    
    int countPartitions(std::vector<int>& nums, int diff) {
       int sum = 0, n = nums.size();
       for (int x : nums) sum += x;

       if ((sum + diff) % 2 != 0 || sum < diff) return 0;
       int target = (sum + diff) / 2;

       std::vector<std::vector<int>> dp(n+1, std::vector<int>(target+1));

       dp[0][0] = 1;

       for (int i = 1; i <= n; ++i) {
          for (int j = 0; j <= target; ++j) {
            dp[i][j] = dp[i-1][j];
            if (nums[i-1] <= j) dp[i][j] += dp[i-1][j - nums[i-1]];
          }
       }

       return dp[n][target];
    }
};

int main() {
    std::vector<int> nums = {1, 3, 3, 2, 1};
    Solution s;
    std::cout << s.countPartitions(nums, 5) << std::endl;
    return 0;
}