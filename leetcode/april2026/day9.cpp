// Question Link : https://leetcode.com/problems/xor-after-range-multiplication-queries-ii/?envType=daily-question&envId=2026-04-09

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long a, long long b) {
        if (b == 0) return 1;
        long long half = power(a, b/2);
        long long res = (half * half) % MOD;

        if (b % 2 == 0) return res = (res * a) % MOD;
        return res;
    }

    int xorAfterQueries(std::vector<int> &nums, std::vector<std::vector<int>> &queries) {
        int n = nums.size();
        int blockSize = std::ceil(std::sqrt(n));
        std::unordered_map<int, std::vector<std::vector<int>>> mpp;

        for (auto &que : queries) {
            int l = que[0], r = que[1], k = que[2], v = que[3];
            if (k >= blockSize) {
                for (int i = l; i <= r; i += k) {
                    // now do what days
                    nums[i] = (nums[i] * v * 1LL) % MOD;
                }
            } else {
                mpp[k].push_back(que);
            }
        }

        for (auto &[K, allQueries] : mpp) {
            std::vector<long long> diff(n, 1);
            for (auto &que : allQueries) {
                int l = que[0], r = que[1], v = que[3];
                diff[l] = (diff[l] * v) % MOD;
                int steps = (r-l) / K;
                int next = l + (steps+1) * K;

                if (next < n) diff[next] = (diff[next] * power(v, MOD-2)) % MOD;
            }

            for (int i = 0; i < n; ++i) {
                if (i-K >= 0) diff[i] = (diff[i] * diff[i-K]) % MOD;
            }

            for (int i = 0; i < n; ++i) {
                nums[i] = (1LL * (nums[i] * diff[i])) % MOD;
            }
        }

        int res = 0;
        for (int n : nums) {
            res ^= n;
        }

        return res;
    }
};