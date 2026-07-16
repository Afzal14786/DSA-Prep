// Question Link : https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16

#include <bits/stdc++.h>
#include <ranges>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int max_i = 0;
        for (int &n : nums) {
            max_i = max(max_i, n);
            n = gcd(n, max_i);
        }

        ranges::sort(nums);

        long long ans = 0;
        for (int i = 0, j = nums.size()-1; i < j; ++i, --j) {
            ans += gcd(nums[i], nums[j]);
        }

        return ans;
    }
};
