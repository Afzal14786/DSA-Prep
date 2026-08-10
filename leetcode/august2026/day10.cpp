
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-iv/?envType=daily-question&envId=2026-08-10

class Solution {
public:
    int dp[100001];

    int solve(int n) {
        if (n <= 0) return n;
        if (dp[n] != -1) return dp[n];

        for (int i = 1; i * i <= n; ++i) {
            if (solve(n - i * i) == 0) return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};