// Question Link : https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Question Link : https://leetcode.com/problems/delete-operation-for-two-strings/description/

#include <iostream>
#include <string>
#include <vector>

/**
 * Recursion
 */

class Recursion {
  public:

    int LCS(std::string &s1, std::string &s2, int m, int n) {
        if (m == 0 || n == 0) return 0;
        if (s1[m-1] == s2[n-1]) return 1 + LCS(s1, s2, m-1, n-1);
        else return std::max(LCS(s1, s2, m-1, n), LCS(s1, s2, m, n-1));
    }

    int minOperations(std::string &s1, std::string &s2) {
        // Your code goes here
        int m = s1.size(), n = s2.size();
        int lcsLength = LCS(s1, s2, m, n);
        std::cout << "LCS : " << lcsLength << std::endl;  // this should return 2.
        return (m-lcsLength) + (n-lcsLength);
    }
};

/**
 * Memoization
 */

class Memoization {
  public:
    int LCS(std::string &s1, std::string &s2, int m, int n, std::vector<std::vector<int>> &dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        if (s1[m-1] == s2[n-1]) return dp[m][n] = 1 + LCS(s1, s2, m-1, n-1, dp);
        else return dp[m][n] = std::max(LCS(s1, s2, m-1, n, dp), LCS(s1, s2, m, n-1, dp));

        return dp[m][n];
    }

    int minOperations(std::string &s1, std::string &s2) {
        // Your code goes here
        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, -1));
        int lengthLCS = LCS(s1, s2, m, n, dp);
        return (m-lengthLCS) + (n-lengthLCS);
    }
};

/**
 * Top-Down
 */

class Solution {
  public:
    int minOperations(std::string &s1, std::string &s2) {
        // Your code goes here

        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return (m - dp[m][n]) + (n - dp[m][n]);
    }
};

int main() {
    std::string s1, s2;
    Solution S1;
    std::cout << "Enter s1 : ";
    std::cin >> s1;

    std::cout << "Enter s2 : ";
    std::cin >> s2;

    std::cout << "Minimum no of operation : " << S1.minOperations(s1, s2) << std::endl;
    return 0;
}