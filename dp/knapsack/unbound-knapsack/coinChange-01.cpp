// Question Link : https://www.geeksforgeeks.org/problems/coin-change2448/1

#include <iostream>
#include <vector>

/**
 * Recursive Code
 */

class Solution {
  public:
    int noOfWays(std::vector<int>& coins, int sum, int n) {
        if (n == 0) return (sum == 0) ? 1 : 0;

        if (coins[n-1] <= sum) {
            return noOfWays(coins, sum - coins[n-1], n) + noOfWays(coins, sum, n-1);
        } else {
            return noOfWays(coins, sum, n-1);
        }
    }

    int count(std::vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        return noOfWays(coins, sum, n);
    }
};

/**
 * Memoization
 */

class Solution {
  public:
    int noOfWays(std::vector<int>& coins, int sum, int n, std::vector<std::vector<int>>& dp) {
        if (n == 0) return (sum == 0) ? 1 : 0;
        if (dp[n][sum] != -1) return dp[n][sum];

        if (coins[n-1] <= sum) {
            return dp[n][sum] = noOfWays(coins, sum - coins[n-1], n, dp) + noOfWays(coins, sum, n-1, dp);
        } else {
            return dp[n][sum] = noOfWays(coins, sum, n-1, dp);
        }
    }

    int count(std::vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(sum+1, -1));
        return noOfWays(coins, sum, n, dp);
    }
};

/**
 * Tabulation
 */

class Solution {
  public:
    int count(std::vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        std::vector<std::vector<int>> dp(n+1, std::vector<int>(sum+1, 0));
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                dp[i][j] = dp[i-1][j];
                if (coins[i-1] <= j) dp[i][j] += dp[i][j - coins[i-1]];
            }
        }

        return dp[n][sum];
    }
};