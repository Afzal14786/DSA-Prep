
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Happy Independence Day
// Question Link : https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/description/?envType=daily-question&envId=2026-08-15

/**
 * @property of XOR
 * x ^ x = 0; means if we xor with the same number we always get zero
 */

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        bool all_zero = true;

        for (int &x : nums) {
            res ^= x;
            if (x != 0) all_zero = false;
        }

        if (all_zero) return 0;
        
        return (res == 0) ? n - 1 : n;
    }
};