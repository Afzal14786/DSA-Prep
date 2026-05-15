// Question Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/?envType=daily-question&envId=2026-05-15

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[high]) high = mid;
            else low = mid + 1;
        }

        return nums[low];
    }
};
