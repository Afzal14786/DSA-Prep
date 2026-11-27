// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/maximum-number-of-items-from-sale-i/description/?envType=daily-question&envId=2026-11-27

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int mult[1501] = {};
        for (auto& it : items) {
            int fac = it[0];
            for (int f = 1; f <= 1500; ++f) {
                if (fac % f == 0) ++mult[f];
            }
        }
        vector<int> dp(budget + 1, 0);
        for (auto& it : items) {
            int f = it[0], p = it[1];
            vector<int> ndp = dp;
            for (int b = budget; b >= p; --b) {
                ndp[b] = max(ndp[b], dp[b - p] + mult[f]);
            }
            for (int b = p; b <= budget; ++b) {
                ndp[b] = max(ndp[b], ndp[b - p] + 1);
            }
            dp = move(ndp);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();