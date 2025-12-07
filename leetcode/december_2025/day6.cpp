// You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

// Return the total number of ways to partition nums under this condition.
// Since the answer may be too large, return it modulo 10^9 + 7.

// Example 1:

// Input: nums = [9,4,1,3,7], k = 4
// Output: 6

// Explanation:
// There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

//     [[9], [4], [1], [3], [7]]
//     [[9], [4], [1], [3, 7]]
//     [[9], [4], [1, 3], [7]]
//     [[9], [4, 1], [3], [7]]
//     [[9], [4, 1], [3, 7]]
//     [[9], [4, 1, 3], [7]]

// Example 2:

// Input: nums = [3,3,4], k = 0
// Output: 2

// Explanation:
// There are 2 valid partitions that satisfy the given conditions:

//     [[3], [3], [4]]
//     [[3, 3], [4]]

// Constraints:

//     2 <= nums.length <= 5 * 104
//     1 <= nums[i] <= 10^9
//     0 <= k <= 10^9

// Submission Link : https://leetcode.com/submissions/detail/1848094446/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = (int)nums.size();

        int dp[n + 1];
        int psum[n + 1];
        
        dp[0]   = 1;
        psum[0] = 1;

        //increasing
        deque<int> inc;
        //decreasing
        deque<int> dec;

        for(int r = 0, l = 0; r < n; r ++){
            while(!inc.empty() && nums[inc.back()] >= nums[r]){
                inc.pop_back();
            }
            inc.push_back(r);
            while(!dec.empty() && nums[dec.back()] <= nums[r]){
                dec.pop_back();
            }
            dec.push_back(r);
            while(!inc.empty() && !dec.empty()){
                if(nums[dec.front()] - nums[inc.front()] > k){
                    if(inc.front() == l) inc.pop_front();
                    if(dec.front() == l) dec.pop_front();
                    l += 1;
                }
                else{
                    break;
                }
            }
            int rangedp = psum[r];
            if(l > 0) rangedp -= psum[l - 1];
            rangedp %= mod;
            if(rangedp < 0) rangedp += mod;

            dp[r + 1]   = rangedp;
            psum[r + 1] = (psum[r] + dp[r + 1]) % mod;
        }
        return dp[n];
    }
};