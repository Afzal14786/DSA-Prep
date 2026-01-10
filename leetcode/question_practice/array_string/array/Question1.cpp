/**
 * Two Sum
 * Question Link : https://leetcode.com/problems/two-sum/?envType=problem-list-v2&envId=array
 * Solution Link : https://leetcode.com/problems/two-sum/submissions/1874017248/?envType=problem-list-v2&envId=array
 */

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// Constraints:

//     2 <= nums.length <= 10^4
//     -109 <= nums[i] <= 10^9
//     -109 <= target <= 10^9

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * in this solution we are returning the value instead of returning the index
 */

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size()       ;
        if (n < 2) {
            return {};
        }

        vector<int> ans(2);

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int req = target - nums[i];
            int low = i + 1, high = n - 1;
            while (low <= high )  {
                int mid = low + (high - low) / 2;

                if (nums[mid] == req) {
                    ans[0] = nums[i];
                    ans[1] = nums[mid];
                    return ans;
                } else if (nums[mid] > req) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }

        return ans;
    }
};


class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 2) return {};

        vector<int> ans(2);

        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;

                    return ans;
                }
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        if (size < 2) return {};
        unordered_map<int, int> mapping;
        vector<int> ans(2);

        for (int i = 0; i < size; ++i) {
            int requiredValue = target - nums[i];
            if (mapping.find(requiredValue) != mapping.end()) {
                ans[0] = mapping[requiredValue];
                ans[1] = i;

                return ans;
            }
            mapping[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};


int main() {
    vector<int> nums = {3,3};
    Solution s;

    vector<int> ans = s.twoSum(nums, 6);
    for (int n : ans) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}