// Question Link : https://leetcode.com/problems/maximum-path-score-in-a-grid/?envType=daily-question&envId=2026-04-30

#include <iostream>
#include <vector>

/**
 * Recursion
 */
class Solution {
public:
    int m, n;
    int MIN = -1e9;
    int solve(int row, int col, std::vector<std::vector<int>>& grid, int k, int cost) {
        if (row >= m || col >= n) return MIN;

        int newCost = cost + ((grid[row][col] > 0) ? 1 : 0);

        if (newCost > k) return MIN;
        // check the boundry
        if (row == m-1 && col == n-1) return grid[row][col];

        int right = solve(row, col+1, grid, k, newCost);
        int down = solve(row+1, col, grid, k, newCost);

        if (right == MIN && down == MIN) return MIN;

        return std::max(right, down) + grid[row][col];
    }

    int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
        int cost = 0;
        m = grid.size();
        n = grid[0].size();

        int ans = solve(0, 0, grid, k, cost);
        return (ans < k) ? -1 : ans;
    }
};

/**
 * Memoization
 */

class Solution {
public:
    int MIN = -1e9;
    int m, n;

    int solve(int row, int col, std::vector<std::vector<int>>& grid, int k, int cost, std::vector<std::vector<std::vector<int>>> &dp) {
        // base case 
        if (row >= m || col >= n) return MIN;
        int newCost = cost + ((grid[row][col] > 0) ? 1 : 0);
        if (newCost > k) return MIN;

        if (row == m-1 && col == n-1) return grid[row][col];

        if (dp[row][col][cost] != -1) return dp[row][col][cost];

        int right = solve(row, col + 1, grid, k, newCost, dp);
        int down = solve(row + 1, col, grid, k, newCost, dp);

        int bestNext = std::max(right, down);
        if (bestNext == MIN) return dp[row][col][cost] = MIN;

        return dp[row][col][cost] = grid[row][col] + bestNext;
    }

    int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        int cost = 0;
        std::vector<std::vector<std::vector<int>>> dp(m+1, std::vector<std::vector<int>>(n+1, std::vector<int>(k+1, -1)));

        int res = solve(0,0,grid, k, cost, dp);
        return (res == MIN) ? -1 : res;
    }
};

/**
 * Bottom Up
 */

class Solution {
public:
    int m, n;
    int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
        m = grid.size(), n = grid[0].size();
        std::vector<std::vector<std::vector<int>>> dp(m+1, std::vector<std::vector<int>>(n+1, std::vector<int>(k+1, -1)));

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                for (int cost = k; cost >= 0; --cost) {
                    int newCost = cost + (grid[i][j] > 0);
                    if (newCost > k) continue;

                    if (i == m-1 && j == n-1) {
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int down = -1, right = -1;
                    if (i+1 < m)
                        down = dp[i+1][j][newCost];
                    
                    if (j+1 < n)
                        right = dp[i][j+1][newCost];

                    int bestNext = std::max(down, right);

                    if (bestNext != -1) {
                        dp[i][j][cost] = bestNext + grid[i][j];
                    }
                }
            }
        }

        return dp[0][0][0];
    }
};