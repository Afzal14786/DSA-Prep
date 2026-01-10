/**
 * Contains Duplicate II
 * Question Link : https://leetcode.com/problems/contains-duplicate-ii/description/
 */

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true

// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true

// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

 

// Constraints:

//     1 <= nums.length <= 10^5
//     -109 <= nums[i] <= 10^9
//     0 <= k <= 105



#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Approach is corrct but there is TLE
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] == nums[j] && abs(i-j) <= k) return true;
            }
        }

        return false;
    }
};

// Solution Link :https://leetcode.com/problems/contains-duplicate-ii/submissions/1872208266/
class Solution2 {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;

        for (int i = 0; i < n; ++i) {
            if (i > k) {
                s.erase(nums[i-k-1]);
            }

            if (s.count(nums[i])) return true;
            s.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    vector<int> num1 = {1,2,3,1,2,3};
    vector<int> num2 = {1,2,3,1};
    vector<int> num3 = {1,0,1,1};

    Solution s1;
    bool ans = s1.containsNearbyDuplicate(num1, 2);
    cout << ((ans == 1) ? "true" : "false") << endl;

    return 0;
}