// question link : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/


#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int solve(int i, int j, std::vector<int>& cuts, std::vector<std::vector<int>> &dp) {
        if (j - i <= 1) return 0;
        int min_cost = 1e9;
        for (int k = i + 1; k < j; ++k) {
            int currCost = (cuts[j] - cuts[i]) + solve(i, k, cuts, dp) + solve(k, j, cuts, dp);
            min_cost = std::min(min_cost, currCost);
        }

        return dp[i][j] = min_cost;
    }

    int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int size = cuts.size();
        std::sort(cuts.begin(), cuts.end());
        std::vector<std::vector<int>> dp(size+1, std::vector<int>(n+1, -1));
        return solve(0, size-1, cuts, dp);
    }
};