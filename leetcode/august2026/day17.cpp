
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/stone-game-v/?envType=daily-question&envId=2026-08-17


class Solution {
public:
    int memo[501][501];
    int solve(int l, int r, vector<int> &prefix_sum) {
        if (l >= r) return 0;

        if (memo[l][r] != -1) return memo[l][r];
        int score = 0;

        for (int mid = l; mid <= r-1; ++mid) {
            int left_sum  = prefix_sum[mid] - (l-1 >= 0 ? prefix_sum[l-1] : 0);
            int right_sum = prefix_sum[r] - prefix_sum[mid];

            if (left_sum < right_sum) {
                score = max(score, left_sum + solve(l, mid, prefix_sum));       
            } else if (left_sum > right_sum) {
                score = max(score, right_sum + solve(mid + 1, r, prefix_sum));
            } else {
                score = max({score, left_sum + solve(l, mid, prefix_sum), right_sum + solve(mid + 1, r, prefix_sum)});
            }
        }

        return memo[l][r] = score;
    }

    int stoneGameV(vector<int>& stone_values) {
        int n = stone_values.size();
        memset(memo, -1, sizeof(memo));
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = stone_values[0];

        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i-1] + stone_values[i];
        }

        return solve(0, n-1, prefix_sum);
    }
};
