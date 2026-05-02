// Question Link : https://leetcode.com/problems/longest-palindromic-subsequence/description/
// Question Link : 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * recurion
 */
class Recursion {
public:
    int LCS(std::string &s1, std::string &s2, int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (s1[m-1] == s2[n-1]) return 1 + LCS(s1, s2, m-1, n-1);
        else return std::max(LCS(s1, s2, m-1, n), LCS(s1, s2, m, n-1));
    }

    int longestPalindromeSubseq(std::string s1) {
        std::string s2 = s1;
        std::reverse(s2.begin(), s2.end());
        int m = s1.size();
        return LCS(s1, s2, m, m);
    }
};

/**
 * memoization
 */

class Solution {
public:
    int LCS(std::string &s1, std::string &s2, int m, int n, std::vector<std::vector<int>> &dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        if (s1[m-1] == s2[n-1]) return dp[m][n] = 1 + LCS(s1, s2, m-1, n-1, dp);
        else return dp[m][n] = std::max(LCS(s1, s2, m-1, n, dp), LCS(s1, s2, m, n-1, dp));
    }

    int longestPalindromeSubseq(std::string s1) {
        std::string s2 = s1;
        std::reverse(s2.begin(), s2.end());
        int m = s1.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(m+1, -1));
        return LCS(s1, s2, m, m, dp);
    }
};

/**
 * top down
 */

class Solution {
public:
    int longestPalindromeSubseq(std::string s1) {
        std::string s2 = s1;
        std::reverse(s2.begin(), s2.end());
        int m = s1.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(m+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][m];
    }
};