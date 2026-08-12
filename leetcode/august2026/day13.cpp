
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2026-08-12

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int i = 0, j = 0;
        unordered_map<int, int> mpp;

        while (j < n) {
            mpp[nums[j]]++;
            while (i < j && mpp[nums[j]] > k) {
                mpp[nums[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }

        return res;
    }
};

