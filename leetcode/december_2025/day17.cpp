// You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

// You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

// Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

// Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

// Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

// Return the maximum total profit you can earn by making at most k transactions.

// Example 1:

// Input: prices = [1,7,9,8,2], k = 2
// Output: 14

// Explanation:
// We can make $14 of profit through 2 transactions:

//     A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
//     A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.

// Example 2:

// Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
// Output: 36

// Explanation:
// We can make $36 of profit through 3 transactions:

//     A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
//     A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
//     A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.

// Constraints:

//     2 <= prices.length <= 103
//     1 <= prices[i] <= 109
//     1 <= k <= prices.length / 2


// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/?envType=daily-question&envId=2025-12-17
// Solution Link : 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long solve(int i,  int state, vector<int>& prices, int k,
                    vector<vector<vector<long long>>>& dp) {

        if (k < 0) {
            return -1e9;
        }
        if (i == prices.size()) {

            if (state == 0) {
                return 0;
            }

            return -1e9;
        }
        if (dp[i][k][state] != -1) {
            return dp[i][k][state];
        }

        //

        long long normal = -1e9;
        long long shortSell = -1e9;
        long long skip = solve(i + 1,  state, prices, k, dp);

        if (state == 0) {
            normal = -prices[i] + solve(i + 1, 1, prices, k, dp);
            shortSell = prices[i] + solve(i + 1, 2, prices, k, dp);

        }

        else if (state == 1) {
            normal = prices[i] + solve(i + 1, 0, prices, k - 1, dp);

        } else {
            shortSell = -prices[i] + solve(i + 1, 0, prices, k - 1, dp);
        }

        return dp[i][k][state] = max(normal, max(shortSell, skip));
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

            vector<vector<vector<long long>>> dp(
n, vector<vector<long long>>(k+1, vector<long long>(3, -1)));
            return solve(0, 0, prices, k, dp);
    }
};