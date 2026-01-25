/**
 * Minimum Difference Between Highest And Lowest Of K Scores
 * Question Link : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/?envType=daily-question&envId=2026-01-25
 * Solution Link : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/submissions/1896321424/?envType=daily-question&envId=2026-01-25
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k <= 0) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, right = k-1;
        int min_score = INT_MAX;
        while (right < n) {
            min_score = min(min_score, nums[right] - nums[left]);
            left++;
            right++;
        }
        return (min_score == INT_MAX) ? 0 : min_score;
    }
};