// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        // brute force solution
        int n = nums.size();
        vector<int> cum_sum(n, 0);
        int max_len = 0;
        unordered_map<int, int> mpp;
        
        for (int r = 0; r < n; ++r) {
            int val = (nums[r] % 2 == 0) ? 1 : -1;
            int prev = -1;

            if (mpp.count(nums[r])) prev = mpp[nums[r]];

            if (prev != -1) {
                for (int l = 0; l <= prev; ++l) {
                    cum_sum[l] -= val;
                }
            }

            for (int l = 0; l <= r; ++l) cum_sum[l] += val;

            for (int l = 0; l <= r; ++l) {
                if (cum_sum[l] == 0) {
                    max_len = max(max_len, r - l + 1);
                    break;;
                }
            }

            mpp[nums[r]] = r;
        }

        return max_len;
    }
};