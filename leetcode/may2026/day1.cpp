// Question Link : https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-05-01

#include <iostream>
#include <vector>

class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int sum = 0, n = nums.size();
        int F = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            F += i * nums[i];
        }
        int res = F;

        for (int k = 0; k < n; ++k) {
            int newF = F + sum - n * nums[n-1-k];
            res = std::max(res, newF);
            F = newF;
        }

        return res;
    }
};