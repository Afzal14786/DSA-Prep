// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/minimum-score-by-changing-two-elements/?envType=daily-question&envId=2026-11-19

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return min(nums[n - 1] - nums[2], min(nums[n - 2] - nums[1], nums[n - 3] - nums[0]));
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();