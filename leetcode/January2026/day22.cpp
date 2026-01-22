/**
 * Minimum Pair Removal To Sort Array I
 * Question Link : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/?envType=daily-question&envId=2026-01-22
 * Solution Link : https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/submissions/1893119534/?envType=daily-question&envId=2026-01-22
 */

// Given an array nums, you can perform the following operation any number of times:

//  - Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
//  - Replace the pair with their sum.

// Return the minimum number of operations needed to make the array non-decreasing.

// Note : An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

// Example 1:

// Input: nums = [5,2,3,1]
// Output: 2

// Explanation:

// - The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// - The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:

// Input: nums = [1,2,2]
// Output: 0

// Explanation:
// The array nums is already sorted.

// Constraints:
//  1 <= nums.length <= 50
//  -1000 <= nums[i] <= 1000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            int min = 1e9;
            int idx = 0;
            count++;

            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] + nums[i + 1] < min) {
                    min = nums[i] + nums[i+1];
                    idx = i;
                }
            }

            vector<int> ans;
            for (int i = 0; i < nums.size(); ++i) {
                if (idx != i) {
                    ans.push_back(nums[i]);
                } else {
                    ans.push_back(min);
                    i++;
                }
            }

            nums = ans;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5,2,3,1};
    vector<int> nums2 = {1,2,2};
    cout << "Minimum number of operations : " << (s.minimumPairRemoval(nums)) << endl;  // 2
    cout << "Minimum number of operations : " << (s.minimumPairRemoval(nums2)) << endl;  // 0
    return 0;
}