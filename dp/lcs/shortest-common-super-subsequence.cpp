// Question Link : https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

#include <iostream>
#include <string>
#include <vector>

/**
 * Recursion
 */

class Solution {
  public:
    int solve(std::string &s1, std::string &s2, int m, int n) {
        if (m == 0 || n == 0) return 0;

        if (s1[m-1] == s2[n-1]) return 1 + solve(s1, s2, m-1, n-1);
        else return std::max(solve(s1, s2, m-1, n), solve(s1, s2, m, n-1));
    }

    int minSuperSeq(std::string &s1, std::string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        return abs((m+n) - solve(s1, s2, m, n));
    }
};

// memoization

class Solution {
  public:
    int solve(std::string &s1, std::string &s2, int m, int n, std::vector<std::vector<int>> &dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        if (s1[m-1] == s2[n-1]) {
            return dp[m][n] = 1 + solve(s1, s2, m-1, n-1, dp);
        } else {
            return dp[m][n] = std::max(solve(s1, s2, m-1, n, dp), solve(s1, s2, m, n-1, dp));
        }
    }

    int minSuperSeq(std::string &s1, std::string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, -1));
        return abs((m+n) - solve(s1, s2, m, n, dp));
    }
};

// top- down approach

class Solution {
  public:

    int minSuperSeq(std::string &s1, std::string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return abs((m+n) - dp[m][n]);
    }
};
