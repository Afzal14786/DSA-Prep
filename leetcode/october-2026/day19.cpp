// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/find-target-indices-after-sorting-array/?envType=daily-question&envId=2026-10-19

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) 
            if(nums[i] == target)
                ans.push_back(i);

        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();