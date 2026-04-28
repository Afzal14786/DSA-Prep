#include <iostream>
#include <vector>

/**
 * Calculating the maximum profit
 * Recursive Solution .. Here we are maximizing the profit .......
 * Time Complexity : O(2^n - 1)
 */
int rodCuttingMaxProfit(std::vector<int> price, std::vector<int> length, int rodLength, int n) {
    // base case 
    if (rodLength == 0 || n == 0) return 0;

    // when to include or not
    // we are going to include and exclude based on condition
    if (length[n - 1] <= rodLength) {
        // here we have option to include or not to include and calculate the profile and return the maximum profit 
        return std::max(price[n - 1] + rodCuttingMaxProfit(price, length, rodLength - length[n - 1], n), rodCuttingMaxProfit(price, length, rodLength, n-1));
    } else {
        return rodCuttingMaxProfit(price, length, rodLength, n-1);
    }
}

/**
 * memoization of maximum profit
 */

int rodCuttingMaxProfit_Memo(std::vector<int> price, std::vector<int> length, int rodLength, int n, std::vector<std::vector<int>> &dp){
    // base case 
    if (rodLength == 0 || n == 0) return 0;

    if (dp[n][rodLength] != -1) return dp[n][rodLength];

    if (length[n-1] <= rodLength) {
        return dp[n][rodLength] = std::max(price[n-1] + rodCuttingMaxProfit_Memo(price, length, rodLength - length[n-1], n, dp), rodCuttingMaxProfit_Memo(price, length, rodLength, n-1, dp));
    } else {
        return dp[n][rodLength] = rodCuttingMaxProfit_Memo(price, length, rodLength, n-1, dp);
    }
    
}

/**
 * Top Down Approach for maximum profit
 */

int rodCuttingMaxProfit_DP(std::vector<int> price, std::vector<int> length, int rodLength) {
    int n = price.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(rodLength+1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= rodLength; ++j) {
            if (length[i-1] <= j) {
                // then include 
                dp[i][j]  = std::max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][rodLength];
}


int minCost(int n, std::vector<int>& cuts) {
    return 0;
}

int main() {
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    std::vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLength = 8;
    int n = prices.size();
    std::vector<std::vector<int>> dp(n+1, std::vector<int>(rodLength+1, -1));

    std::cout << "Maximum Profit After Cutting The Rod & Selling It : " << rodCuttingMaxProfit_DP(prices, length, rodLength) << std::endl;

    // std::vector<int> cust = {1,3,4,5};
    // int n = 7;
    // std::cout << "Minimum Cost To Cut A Stick Is : " << minCost(n, cust) << std::endl;
    return 0;
}