/**
 * Question Link (GFG) : https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
 * Question Link (LeetCode) : https://leetcode.com/problems/longest-common-subsequence/
 */
#include <iostream>
#include <string>
#include <vector>

// recursion code
class Solution2 {
public:
    int solve(std::string &x, std::string &y, int m, int n) {
        if (m == 0 || n == 0) return 0;

        // now the choice diagram
        if (x[m-1] == y[n-1]) return 1 + solve(x, y, m-1, n-1);
        else return std::max(solve(x, y, m, n-1), solve(x, y, m-1, n));
    }

    int longestCommonSubsequence(std::string &a, std::string &b) {
        int m = a.size(), n = b.size();
        return solve(a, b, m, n);
    }
};

// memoization : 

class Solution {
  public:
    int memoization(std::string &str1, std::string &str2, int m, int n, std::vector<std::vector<int>>& dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        if (str1[m-1] == str2[n-1]) return dp[m][n] = 1 + memoization(str1, str2, m-1, n-1, dp);
        else return dp[m][n] = std::max(memoization(str1, str2, m-1, n, dp), memoization(str1, str2, m, n-1, dp));
    }

    int lcs(std::string &s1, std::string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, -1));

        return memoization(s1, s2, m, n, dp);
    }
};

/**
 * Top Down Approach
 */

class Solution {
  public:
    int lcs(std::string &s1, std::string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] += 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
};


int main() {
    std::string a, b;
    std::cout << "Enter First String : ";
    std::cin >> a;

    std::cout << "Enter Second String : ";
    std::cin >> b;

    Solution2 s;
    std::cout << "Longest Common Subsequence : " << s.longestCommonSubsequence(a, b) << std::endl;
    
    return 0;
}