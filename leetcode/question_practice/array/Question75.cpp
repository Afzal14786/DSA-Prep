/**
 * Sort Colors
 * Question Link : https://leetcode.com/problems/sort-colors/description/?envType=problem-list-v2&envId=array
 * Solution Link : https://leetcode.com/problems/sort-colors/submissions/1872909565/?envType=problem-list-v2&envId=array
 */

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:

//     n == nums.length
//     1 <= n <= 300
//     nums[i] is either 0, 1, or 2.

// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // using quick sort
        for (int i = 1; i < nums.size(); ++i) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j -= 1;
            }
            nums[j + 1] = key;
        }

        for (int n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2,0,2,1,1,0};
    s.sortColors(nums);         
    return 0;
}