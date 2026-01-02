/**
 * Contains Duplicate III
 * Question Link : https://leetcode.com/problems/contains-duplicate-iii/description/
 * Solution Link : 
 */

// You are given an integer array nums and two integers indexDiff and valueDiff.

// Find a pair of indices (i, j) such that:

//     i != j,
//     abs(i - j) <= indexDiff.
//     abs(nums[i] - nums[j]) <= valueDiff, and

// Return true if such pair exists or false otherwise.

// Example 1:

// Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
// Output: true
// Explanation: We can choose (i, j) = (0, 3).
// We satisfy the three conditions:
// i != j --> 0 != 3
// abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
// abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

// Example 2:

// Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
// Output: false
// Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false. 

// Constraints:

//     2 <= nums.length <= 10^5
//     -109 <= nums[i] <= 10^9
//     1 <= indexDiff <= nums.length
//     0 <= valueDiff <= 10^9

 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

// simple solution
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[i] == nums[j] && abs(i - j) == indexDiff && abs(nums[i] - nums[j]) == valueDiff) return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> num1 = {1,2,3,1};
    vector<int> num2 = {1,5,9,1,5,9};

    Solution s1, s2;

    cout << ((s1.containsNearbyAlmostDuplicate(num1, 3, 0) ? "true" : "false")) << endl;

    cout << ((s2.containsNearbyAlmostDuplicate(num2, 2, 3) ? "true" : "false")) << endl;
    return 0;
}