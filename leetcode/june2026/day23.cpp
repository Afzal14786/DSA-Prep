// Question Link : https://leetcode.com/problems/number-of-zigzag-arrays-i/description/?envType=daily-question&envId=2026-06-23 
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <map>

using namespace std;

class Solution {
public:
    static constexpr int MOD = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {
            reverse(dp.begin(), dp.end());
            int sum = 0;
            for (auto& d : dp)
                sum = (sum + exchange(d, sum)) % MOD;
        }

        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
    }
};

class Solution {
    inline static map<pair<int, int>, int> cache = {};
    inline static constexpr int MOD = 1000000007;
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        pair<int, int> k = {n, m};

        if (cache.count(k)) return cache[k];

        vector<int> dp(m, 1);

        for (int i = 1; i < n; i++) {
            reverse(dp.begin(), dp.end());
            int sum = 0, pref = 0;

            for (int j = 0; j < m; j++) {
                sum = (sum + exchange(dp[j], sum)) % MOD;
                pref = (pref + dp[j]) % MOD;
            }

            cache[{i + 1, m}] = (pref * 2LL) % MOD;
        }

        return cache[k] =
            ((accumulate(dp.begin(), dp.end(), 0LL) % MOD)<<1) % MOD;
    }
};
