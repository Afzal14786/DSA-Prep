// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-viii/description/?envType=daily-question&envId=2026-08-24

// time limit exceeded -- solution
class Solution {
public:
    // int n;
    int dp[100001];
    int solve(int i, int n, vector<int> &prefix_sum) {
        if (i == n-1) return prefix_sum[n-1];

        if (dp[i] != -1) return dp[i];

        int take = prefix_sum[i] - solve(i+1, n, prefix_sum);
        int skip = solve(i+1, n, prefix_sum);

        return dp[i] = max(take, skip);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        memset(dp, -1, sizeof(dp));

        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + stones[i];
        }

        return solve(1, n, prefix_sum);
    }
};

// bottom up 
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = stones[0];

        for (int i = 1; i < n; ++i) prefix_sum[i] = prefix_sum[i-1] + stones[i];

        vector<int> dp(n, 0);
        dp[n-1] = prefix_sum[n-1];

        for (int i = n-2; i >= 1; --i) {
            int take = prefix_sum[i] - dp[i+1];
            int skip = dp[i+1];

            dp[i] = max(take, skip);
        }
        return dp[1];
    }
};
