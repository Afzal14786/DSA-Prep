/**
 * Minimum ASCII Delete Sum For Two String
 * Question Link : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10
 * Solution Link : 
 */

// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

// Constraints:

//  1 <= s1.length, s2.length <= 1000
//  s1 and s2 consist of lowercase English letters.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if (i == s1.size() && j == s2.size()) return 0;

        if (i == s1.size()) {
            int ans = 0;
            while (j < s2.size()) {
                ans += s2[j];
                j++;
            }
            return ans;
        }

        if (j == s2.size()) {
            int ans = 0;
            while (i < s1.size()) {
                ans += s1[i];
                i++;
            }
            return ans;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s1[i] == s2[j]) {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
        } else {
            return dp[i][j] = min(solve(i + 1, j, s1, s2, dp) + s1[i], solve(i, j + 1, s1, s2, dp) + s2[j]);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, s1, s2, dp);
    }
};

int main() {
    string s1 = "delete";
    string s2 = "leet";
    Solution s;
    cout << "Sum Of Deleted ASCII " << (s.minimumDeleteSum(s1, s2)) << endl;
    return 0;
}