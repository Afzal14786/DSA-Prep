#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/smallest-stable-index-ii/description/?envType=daily-question&envId=2026-09-05

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxSoFar = -1;
        int cand = 0, cMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar, nums[i]);

            if (i == cand) cMax = maxSoFar;

            if (nums[i] < cMax - k)
                cand = i + 1;
        }

        return cand < nums.size() ? cand : -1;
    }
};
