// Question Link : https://leetcode.com/problems/maximum-total-subarray-value-i/?envType=daily-question&envId=2026-06-09

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int g_min = nums.front(), g_max = nums.front();

        for (auto &n : nums) {
            g_min = min(g_min, n);
            g_max = max(g_max, n);
        }

        return (long long) (g_max - g_min) * k;
    }
};


class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto [min, max] = std::ranges::minmax(nums);
        return (long long)(max - min) * k;
    }
};

int main() {
    
    return 0;
}