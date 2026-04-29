// Question Link : https://leetcode.com/problems/maximum-score-from-grid-operations/?envType=daily-question&envId=2026-04-29

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstring>

//Approach-1 (Brute Force) - TLE
//T.C : O((n+1)^n * n^2))
//S.C : O(n)


class Solution {
public:
    long long computeRes(std::vector<int>&H, std::vector<std::vector<int>>& grid, int n) {
        long long score = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = H[j] + 1; i < n; ++i) {
                bool hasBlackNeighbour = false;
                if (j - 1 >= 0 && i <= H[j-1]) hasBlackNeighbour = true;
                if (j + 1 < n && i <= H[j+1]) hasBlackNeighbour = true;

                if (hasBlackNeighbour) score += grid[i][j];
            }
        }
        return score;
    }

    void solve(int col, std::vector<int>& H, std::vector<std::vector<int>> &grid, long long &res, int n) {
        if (col == n) {
            res = std::max(res, computeRes(H, grid, n));
            return;
        }

        for (int height = -1; height < n; ++height) {
            H[col] = height;
            solve(col+1, H, grid, res, n);
        }
    }

    long long maximumScore(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> H(n);
        long long res = 0;
        solve(0, H, grid, res, n);
        return res;
    }
};

//Approach-3 (Most optimal)
//T.C : O(n^3)
//S.C : O(n^2)

class Solution {
public:
    typedef long long ll;
    int n;
    ll t[2][101][101];

    ll solve(bool prevTaken, int prevHeight, int col, std::vector<std::vector<int>>& grid, std::vector<std::vector<ll>>& colPrefSum) {
        
        if(col == n) {
            return 0;
        }
        
        ll result = 0;

        if(t[prevTaken][prevHeight][col] != -1) {
            return t[prevTaken][prevHeight][col];
        } 

        for(int height = 0; height <= n; height++) {
            ll prevColScore = 0;
            ll currColScore = 0;

            if(!prevTaken && col-1 >= 0 && height > prevHeight) {
                prevColScore += colPrefSum[height][col] - colPrefSum[prevHeight][col];
            }

            if(prevHeight > height) {
                currColScore += colPrefSum[prevHeight][col+1] - colPrefSum[height][col+1];
            }


            ll currColScoreTaken    = currColScore + prevColScore + solve(true, height, col+1, grid, colPrefSum);
            ll currColScoreNotTaken = prevColScore + solve(false, height, col+1, grid, colPrefSum);

            result = std::max({result, currColScoreTaken, currColScoreNotTaken});
        }

        return t[prevTaken][prevHeight][col] = result;

    }

    long long maximumScore(std::vector<std::vector<int>>& grid) {
        n = grid.size();

        memset(t, -1, sizeof(t));


        std::vector<std::vector<ll>> colPrefSum(n + 1, std::vector<ll>(n + 1, 0));

        for(int col = 1; col <= n; col++) {
            for(int row = 1; row <= n; row++) {
                colPrefSum[row][col] = colPrefSum[row-1][col] + grid[row-1][col-1];
            }
        }

        return solve(false, 0, 0, grid, colPrefSum);
    }
};

