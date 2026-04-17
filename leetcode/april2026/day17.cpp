// Question Link : https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/?envType=daily-question&envId=2026-04-17

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    /**
     * Time Compexity : log10
     */
    int getRevers(int n) {
        int rev = 0;
        while (n > 0) {
            int rem = n % 10;
            rev = rev * 10 + rem;
            n /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(std::vector<int>& nums) {
        int n = nums.size();
        int min_dist = 1e9;
        /**
         * Space Complexity : O(N) ~ For storing alteration
         */
        std::unordered_map<int, int> mpp; // <value, idx>

        /**
         * Time Complexity :O(N) for loop and O(log) So overall O(N * logn)
         */
        for (int i = 0; i < n; ++i) {
            if (mpp.count(nums[i])) min_dist = std::min(min_dist, i - mpp[nums[i]]);
            mpp[getRevers(nums[i])] = i;
        }

        return min_dist == 1e9 ? -1 : min_dist;
    }
};