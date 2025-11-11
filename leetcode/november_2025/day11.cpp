// You are given an array of binary strings strs and two integers m and n.
// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// A set x is a subset of a set y if all elements of x are also elements of y.

// Example 1:
// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

// Example 2:
// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.

// Constraints:

//     1 <= strs.length <= 600
//     1 <= strs[i].length <= 100
//     strs[i] consists only of digits '0' and '1'.
//     1 <= m, n <= 100

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <ranges>

/**
 * Tough times are the parts of our journey
 * Face it  ---> Embrace It
 *          It will make you strong
 *          Stay on your path
 */

// Question Link : https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11
// Solution Link : 

using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        auto &n0 = m, &n1 = n;
        array<array<int, 101>, 101> dp{};
        for (auto& str : strs) { // O (600 *100 *100) == 6e6
            int c0 = ranges::count(str, '0');
            int c1 = str.size() - c0;
            // add this substr, only once
            for (int i = m; i >= c0; --i)
                for (int j = n; j >= c1; --j) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c0][j - c1]);
                }
        }
        return dp[m][n];
    }
};