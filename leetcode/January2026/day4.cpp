/**
 * Four Divisor
 * Question Link : https://leetcode.com/problems/four-divisors/?envType=daily-question&envId=2026-01-04
 * Solution Link : https://leetcode.com/problems/four-divisors/submissions/1873822345/?envType=daily-question&envId=2026-01-04
 */

// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.

// Example 2:

// Input: nums = [21,21]
// Output: 64

// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 0

// Constraints:

//     1 <= nums.length <= 104
//     1 <= nums[i] <= 105


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findSumDivisor(int num) {
        int count = 0;
        int sum = 0;
        for (int fact = 1; fact * fact <= num; ++fact) {
            if (num % fact == 0) {
                int other = num / fact;
                if (other == fact) {
                    count += 1;
                    sum += fact;
                } else {
                    count += 2;
                    sum += fact + other;
                }
            }

            if (count > 4) {
                return 0;
            }
        }

        if (count == 4) {
            return sum;
        }
        return 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int res = 0;

        for (int &num : nums) {
            res += findSumDivisor(num);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {21, 21};
    Solution s;
    cout << "Sum of the divisor is " << ((s.sumFourDivisors(nums))) << endl;
    return 0;
}