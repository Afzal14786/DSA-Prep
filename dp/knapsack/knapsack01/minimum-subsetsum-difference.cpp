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

/**
 * Recursion Solution
 * Time Complexity : O(2 ^ N)
 * Space Complexity : O(N)
 */

class Solution {
  public:
    int solve(std::vector<int> &nums, int n, int currSum, int range) {
        if (n == 0) return abs((range - currSum) - currSum);

        int include = solve(nums, n-1, currSum + nums[n-1], range);
        int exclude = solve(nums, n-1, currSum, range);

        return std::min(include, exclude);
    }

    int minDifference(std::vector<int>& arr) {
        // code here
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }

        return solve(arr, arr.size(), 0, sum);
    }
};


/**
 * Using Memoization
 * Time Complexity : O(N * range)
 * Space Complexity : O(N * range)
 */

class Solution {
  public:
    int solve(std::vector<int> &nums, int n, int currSum, int range, std::vector<std::vector<int>> &dp) {
        if (n == 0) return abs(range - 2 * currSum);

        if (dp[n][currSum] != -1) return dp[n][currSum];

        int include = solve(nums, n-1, currSum + nums[n-1], range, dp);
        int exclude = solve(nums, n-1, currSum, range, dp);

        return dp[n][currSum] = std::min(include, exclude);
    }

    int minDifference(std::vector<int>& arr) {
        // code here
        int range = 0;
        for (int x : arr) range += x;

        std::vector<std::vector<int>> dp(arr.size()+1, std::vector<int>(range+1, -1));
        return solve(arr, arr.size(), 0, range, dp);
    }
};

/**
 * Top Down Approach
 * Time Complexity : O(N * range)
 * Space Complexity : O(N * range)
 */

class Solution {
  public:
    int minDifference(std::vector<int>& arr) {
        int range = 0;
        for (int x : arr) range += x;
        int n = arr.size();
        
        std::vector<std::vector<bool>> dp(arr.size() + 1, std::vector<bool>(range + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= arr.size(); ++i) {
            for (int j = 0; j <= range; ++j) { 
                dp[i][j] = dp[i-1][j];  // excluding 

                if (arr[i-1] <= j) {
                    dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]]; 
                }
            }
        }

        int mn = range;

        for (int i = 0; i <= range/2; ++i) {
            if (dp[n][i]) mn = std::min(mn, abs((range - i) - i));
        }

        return mn;
    }
};


/**
 * Space Optimize Code 
 */

class SpaceOptimize {
  public:
    int minDifference(std::vector<int>& arr) {
        // code here
        int range = 0;
        for (int x : arr) range += x;

        std::vector<bool> dp(range+1, false);

        dp[0] = true;

        for (int num : arr) {
            for (int i = range; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }

        int mn = range;

        for (int i = 0; i <= range / 2; ++i) {
            if (dp[i]) {
                mn = std::min(mn, range - 2 * i);
            }
        }

        return mn;
    }
};

int main() {
    std::vector<int> nums = {3,9,7,3};
    SpaceOptimize s;

    std::cout << "Minimum Is : " << s.minDifference(nums) << std::endl;
    return 0;
}