// Question Link : https://www.naukri.com/code360/problems/0-1-knapsack_920542?&interviewProblemRedirection=true&attempt_status=COMPLETED
// Question Link : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <iostream>
#include <vector>

/**
 * Memoization
 */

class Solution {
  public:
    int solve(std::vector<int> &val, std::vector<int> &wt, int n, int W, std::vector<std::vector<int>> &dp) {
        if (n == 0 || W == 0) return 0;
        if (dp[n][W] != -1) return dp[n][W];

        if (wt[n-1] <= W) {
            return dp[n][W] = std::max(val[n-1] + solve(val, wt, n-1, W-wt[n-1], dp), solve(val, wt, n-1, W, dp));
        } else {
            return dp[n][W] = solve(val, wt, n-1, W, dp);
        }
    }

    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt) {
        // code here
        int n = val.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(W+1, -1));
        return solve(val, wt, n, W, dp);
    }
};

/**
 * Top - Down Approach
 */

class Solution {
  public:
    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt) {
        // code here
        int n = wt.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(W+1));

        // initialization
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < W+1; ++j) {
                if (i == 0 || j == 0) dp[i][j] = 0;
            }
        }

        for (int i = 1; i < n+1; ++i) {
            for (int j = 1; j < W+1; ++j) {
                if (wt[i-1] <= j) {
                    dp[i][j] = std::max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
    }
};