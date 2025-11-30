// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

// A subarray is defined as a contiguous block of elements in the array.

// Example 1:

// Input: nums = [3,1,4,2], p = 6
// Output: 1
// Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

// Example 2:

// Input: nums = [6,3,5,2], p = 9
// Output: 2
// Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

// Example 3:

// Input: nums = [1,2,3], p = 3
// Output: 0
// Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.

 

// Constraints:

//     1 <= nums.length <= 10^5
//     1 <= nums[i] <= 10^9
//     1 <= p <= 10^9


// Question Link : https://leetcode.com/problems/make-sum-divisible-by-p/description/?envType=daily-question&envId=2025-11-30
// Solution Link : 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;



class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, set<int>> mp;
        int n = nums.size();
        long long suffix = 0;
        int ans = 1e9;

        for (int i = n-1; i >= 0; --i) {
            suffix = (suffix + nums[i]) % p;
            mp[suffix].insert(i);

            if (suffix == 0) ans = min(ans, i);
        }

        long long prefix = 0;

        for (int i = 0; i < n; ++i) {
            prefix = (prefix + nums[i]) % p;
            int val = p - prefix;

            if (prefix == 0) {
                val = 0;
                ans = min(ans, n-1-i);
            }

            if (mp.find(val) != mp.end()) {
                auto it = mp[val].upper_bound(i);
                if (it != mp[val].end()) {
                    int idx = *it;
                    ans = min(ans, idx - i - 1);
                }
            }
        }

        if (ans == 1e9) return -1;
        return ans;
    }
};