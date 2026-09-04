
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-stable-index-i/description/?envType=daily-question&envId=2026-09-04

class Solution {
public:
    inline static int suf[100];
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        suf[n - 1] = nums.back();

        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);        

        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (maxSoFar - suf[i] <= k)
                return i;
        }

        return -1;
    }
};