
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-missing-elements/?envType=daily-question&envId=2026-08-04

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = 1; i < n; ++i) {
            for (int x = nums[i - 1] + 1; x < nums[i]; ++x) {
                ans.push_back(x);
            }
        }

        return ans;
    }
};