
// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/?envType=daily-question&envId=2026-08-11

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int seq_sum = nums[0];;

        unordered_set<int> st(nums.begin(), nums.end());

        for (int j = 1; j < n; ++j) {
            if (nums[j] == nums[j-1] + 1) {
                seq_sum += nums[j];
            } else
                break;
        }

        while (st.count(seq_sum)) {
            seq_sum++;
        }
        
        return seq_sum;
    }
};
