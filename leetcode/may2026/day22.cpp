// Question Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/?envType=daily-question&envId=2026-05-22

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;

        while (start <= end) {
            int mid = start + (end - start)/2;

            if (nums[mid] == target) {
                return mid; /// means found at mid
            }

            if (nums[start] <= nums[mid]) { // means that the mid exist in line no 1
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid-1;    // search in the left half of the line no 1
                } else {
                    // search in the right half of the line no 1
                    start = mid +  1;
                }
            } else {
                // means that the mid exist in line no 2
                if (nums[mid] < target && target <= nums[end]) {
                    // search in the right half of the line 2
                    start = mid + 1;
                } else {
                    // search in the left half of the line no 2
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};