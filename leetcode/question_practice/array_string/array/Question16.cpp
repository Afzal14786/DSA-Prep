/**
 * 3Sum Closest
 * Question Link : https://leetcode.com/problems/3sum-closest/description/?envType=problem-list-v2&envId=array
 * Solution Link : https://leetcode.com/problems/3sum-closest/submissions/1874050727/?envType=problem-list-v2&envId=array
 */

// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

// Constraints:

//     3 <= nums.length <= 500
//     -1000 <= nums[i] <= 1000
//     -104 <= target <= 104

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 3) return -1;
        sort(nums.begin(), nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < size - 1; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = size - 1;

            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                if (abs(target - currSum) < abs(target - closestSum)) {
                    closestSum = currSum;
                }

                if (currSum < target) {
                    ++left;
                } else if (currSum > target) {
                    --right;
                } else {
                    return target;
                }
            }
        }

        return closestSum;
    }
};

int main() {
    vector<int> nums = {-1,2,1,-4};
    vector<int> nums2 = {0,0,0};
    int target = 1;

    Solution s;
    cout << "Sum for num 1 : " << (s.threeSumClosest(nums, target)) << endl;
    cout << "Sum for num 2 : " << (s.threeSumClosest(nums2, target)) << endl;
    return 0;
}