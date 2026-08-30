// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/removing-minimum-and-maximum-from-array/?envType=daily-question&envId=2026-08-30

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[min_idx]) min_idx = i;
            if (nums[i] > nums[max_idx]) max_idx = i;
        }

        int a = min_idx, b = max_idx;
        if (a > b) swap(a, b);
        int from_front = b + 1;
        int from_back  = n - a;
        int both = (a + 1) + (n - b);

        return min({from_back, from_front, both});
    }
};