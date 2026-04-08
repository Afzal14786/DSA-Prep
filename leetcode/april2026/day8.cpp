// Question Link : https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/?envType=daily-question&envId=2026-04-08

#include <iostream>
#include <vector>

using namespace std;

/**
 * Just do what question describe ...
 */

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        for (auto &queue : queries) {
            int l = queue[0], r = queue[1], k = queue[2], v = queue[3];
            while (l <= r) {
                nums[l] = (1LL * nums[l] * v) % MOD;
                l += k;
            }
        }

        int ans = 0;
        for (int &n : nums) {
            ans ^= n;
        }
        return ans;
    }
};