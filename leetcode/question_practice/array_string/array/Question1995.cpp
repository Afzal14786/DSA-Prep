/**
 * Count Special Quadruplets
 * Question Link : https://leetcode.com/problems/count-special-quadruplets/
 * Solution Link : https://leetcode.com/problems/count-special-quadruplets/submissions/1874656416/
 */

// Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
//     nums[a] + nums[b] + nums[c] == nums[d], and
//     a < b < c < d

// Example 1:

// Input: nums = [1,2,3,6]
// Output: 1
// Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.

// Example 2:

// Input: nums = [3,3,6,4,5]
// Output: 0
// Explanation: There are no such quadruplets in [3,3,6,4,5].

// Example 3:

// Input: nums = [1,1,1,3,5]
// Output: 4
// Explanation: The 4 quadruplets that satisfy the requirement are:
// - (0, 1, 2, 3): 1 + 1 + 1 == 3
// - (0, 1, 3, 4): 1 + 1 + 3 == 5
// - (0, 2, 3, 4): 1 + 1 + 3 == 5
// - (1, 2, 3, 4): 1 + 1 + 3 == 5

// Constraints:

//     4 <= nums.length <= 50
//     1 <= nums[i] <= 100

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        if (size < 4) return count;

        for (int i = 0; i < size - 3; ++i) {
            for (int j = i + 1; j < size - 2; ++j) {
                for (int k = j + 1; k < size - 1; ++k) {
                    for (int l = k + 1; l < size; ++l) {
                        if (nums[i] + nums[j] + nums[k] == nums[l]) {
                            ++count;
                        }
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3,3,6,4,5};
    vector<int> nums1 = {1,2,3,6};
    vector<int> nums2 = {1,1,1,3,5};
    cout << "No Of Count (nums) = " << (s.countQuadruplets(nums)) << endl;   // 0
    cout << "No Of Count (nums 1) = " << (s.countQuadruplets(nums1)) << endl;  // 1
    cout << "No Of Count (nums 2) = " << (s.countQuadruplets(nums2)) << endl;  // 4
    return 0;
}