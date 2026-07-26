// Question Link : https://leetcode.com/problems/maximum-product-of-three-numbers/?envType=daily-question&envId=2026-07-26

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums.back() * nums[n-2] * nums[n-3], nums.back(), nums.front(), nums[1]);
    }
};

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first_max = INT_MIN, second_max = INT_MIN, third_max = INT_MIN;
        int first_min = INT_MAX, second_min = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= first_max) {
                third_max = second_max;
                second_max = first_max;
                first_max = nums[i];
            } else if (nums[i] >= second_max) {
                third_max = second_max;
                second_max = nums[i];
            } else if (nums[i] > third_max) third_max = nums[i];
            if (nums[i] <= first_min) {
                second_min = first_min;
                first_min = nums[i];
            } else if (nums[i] < second_min) {
                second_min = nums[i];
            }
        }

        int a = first_max * second_max * third_max;
        int b = first_min * second_min;

        return max(a, b);
    }
};
