// Question Link : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/?envType=daily-question&envId=2026-05-23

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int pos = 1;
        while(pos < n and nums[pos] >= nums[pos-1])
            pos++;

        if (pos == n)             return true;
        if (nums[pos] > nums[0])  return false;
        if (pos == n-1)           return true;

        pos += 1;

        while (pos < n and nums[pos] <= nums[0] and nums[pos] >= nums[pos-1])
            pos++;

        return pos == n;
    }
};