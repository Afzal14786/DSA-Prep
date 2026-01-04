/**
 * 4Sum
 * Question Link : https://leetcode.com/problems/4sum/description/?envType=problem-list-v2&envId=array
 * Solution Link : https://leetcode.com/problems/4sum/submissions/1874651084/?envType=problem-list-v2&envId=array
 */

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

//     0 <= a, b, c, d < n
//     a, b, c, and d are distinct.
//     nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

// Constraints:

//     1 <= nums.length <= 200
//     -109 <= nums[i] <= 10^9
//     -109 <= target <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size(); 
        vector<vector<int>> ans;

        if (size < 4) return ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < size - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = size - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return ans;

    }
};

int main() {
    Solution S;
    vector<int> nums = {2,2,2,2,2};
    vector<int> nums2 = {1,0,-1,0,-2,2};
    int target = 8;

    vector<vector<int>> ans = S.fourSum(nums, target);
    vector<vector<int>> ans2 = S.fourSum(nums2, 0);

    cout << "Solution 1 : \n";
    for (const auto& arr : ans) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Solution 2 : \n";
    for (const auto& arr : ans2) {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}