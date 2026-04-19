// Question Link : https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/?envType=daily-question&envId=2026-04-19

#include <iostream>
#include <vector>

class Solution {
public:
    int maxDistance(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0, ans = 0;

        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                ans = std::max(ans, j - i);
                j++;
            } else {
                i++;
            }
        }
       return ans;
    }
};