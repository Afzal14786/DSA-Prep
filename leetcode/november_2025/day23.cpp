// Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 

// Example 1:

// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

// Example 2:

// Input: nums = [4]
// Output: 0
// Explanation: Since 4 is not divisible by 3, do not pick any number.

// Example 3:

// Input: nums = [1,2,3,4,4]
// Output: 12
// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).

 

// Constraints:

//     1 <= nums.length <= 4 * 104
//     1 <= nums[i] <= 104


// Question Link : https://leetcode.com/problems/greatest-sum-divisible-by-three/?envType=daily-question&envId=2025-11-23
// Solution LInk : https://leetcode.com/problems/greatest-sum-divisible-by-three/submissions/1837557938/?envType=daily-question&envId=2025-11-23

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        vector<int> rem1;
        vector<int> rem2;

        for (int &num : nums) {
            sum += num;

            if (num % 3 == 1) {
                rem1.push_back(num);
            } else if (num % 3 == 2) {
                rem2.push_back(num);
            }
        }

        if (sum % 3 == 0) return sum;

        sort(begin(rem1), end(end(rem1)));
        sort(begin(rem2), end(end(rem2)));

        int result = 0;
        int reminder = sum % 3;

        if (reminder == 1) {
            int remove1 = rem1.size() >= 1 ? rem1[0] : INT_MAX;
            int remove2 = rem2.size() >= 2 ? (rem2[0] + rem2[1]) : INT_MAX;

            result = max(result, sum - min(remove1, remove2));
        } else {
            int remove1 = rem2.size() >= 1 ? rem2[0] : INT_MAX;
            int remove2 = rem1.size() >= 2 ? (rem1[0] + rem1[1]) : INT_MAX;

            result = max(result, sum - min(remove1, remove2));
        }

        return result;
    }
};

