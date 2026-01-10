
/**
 * Single Number 
 * Question Link : https://leetcode.com/problems/single-number/?envType=problem-list-v2&envId=array
 * Solution Link : 
 */

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:

// Input: nums = [2,2,1]
// Output: 1

// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:

// Input: nums = [1]
// Output: 1

// Constraints:

//     1 <= nums.length <= 3 * 104
//     -3 * 104 <= nums[i] <= 3 * 104
//     Each ele

//     ment in the array appears twice except for one element which appears only once.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int that_value = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            that_value ^= nums[i];
        }

        return that_value;
    }
};


int main() {
    vector<int> nums = {2,2,1};
    Solution2 s1;

    cout << ((s1.singleNumber(nums))) << endl;
    return 0;
}