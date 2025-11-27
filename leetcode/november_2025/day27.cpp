// You are given an array of integers nums and an integer k.

// Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

// Example 1:

// Input: nums = [1,2], k = 1
// Output: 3

// Explanation:
// The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

// Example 2:

// Input: nums = [-1,-2,-3,-4,-5], k = 4
// Output: -10

// Explanation:
// The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

// Example 3:

// Input: nums = [-5,1,2,-3,4], k = 2
// Output: 4
// Explanation:

// The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

// Constraints:

//     1 <= k <= nums.length <= 2 * 105
//     -109 <= nums[i] <= 109

// Question Link : https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/description/?envType=daily-question&envId=2025-11-27
// Solution Link : 
 
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = -1e18;
        long long prefix = 0;

        int n = nums.size();
 
        vector<long long> minPrefix(k, 1e18);
        minPrefix[k-1] = 0;

        for (int i = 0; i < n; ++i) {
            prefix += nums[i];
            int rem = i % k;
            if (i >= k - 1) {
                ans = max(ans, prefix - minPrefix[rem]);
            }
            if (i == k - 1) {
                ans = prefix;
            }

            minPrefix[rem] = min(minPrefix[rem], prefix);
        }

        return ans;
    }
};