// Question Link : https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/?envType=daily-question&envId=2026-07-14

// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int t[201][201][201];
    const int MOD = 1e9 + 7;
    int GCD(int a, int b) {
        return gcd(a, b);
    }

    int solve(vector<int> &nums, int idx, int first_gcd, int second_gcd) {

        if (idx == nums.size()) {
            bool bothNonEmpty = (first_gcd != 0 && second_gcd != 0);
            bool gcd_same = (first_gcd == second_gcd);

            return (bothNonEmpty && gcd_same) ? 1 : 0;
        }

        if (t[idx][first_gcd][second_gcd] != -1) return t[idx][first_gcd][second_gcd];

        int skip = solve(nums, idx+1, first_gcd, second_gcd);
        int seq_1 = solve(nums, idx+1, GCD(first_gcd, nums[idx]), second_gcd);
        int seq_2 = solve(nums, idx+1, first_gcd, GCD(second_gcd, nums[idx]));

        return t[idx][first_gcd][second_gcd] = (0LL + skip + seq_1 + seq_2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};