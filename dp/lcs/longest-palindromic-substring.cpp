// Question Link : https://leetcode.com/problems/longest-palindromic-substring/description/
// Question Link : https://www.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/**
 * This solution is brute force and give us TLE
 */

class Solution {
public:
    std::string solve(std::string &s1, std::string &s2, int m, int n, std::string &ans) {
        if (m == 0 || n == 0) return "";
        
        if (s1[m-1] == s2[n-1]) {
            ans.push_back(s1[m-1]);
            return solve(s1, s2, m-1, n-1, ans);
        }
        // explore all the possible paths
        std::string path1 = solve(s1, s2, m-1, n, ans);
        std::string path2 = solve(s1, s2, m, n-1, ans);

        return (path1.size() > path2.size()) ? path1 : path2;
    }

    std::string longestPalindrome(std::string s) {
        int m = s.size();
        std::string s1 = s;
        std::string ans = "";
        
        std::reverse(s1.begin(), s1.end());
        return solve(s, s1, m, m, ans);
    }
};

/**
 * Memoization
 */

class Solution {
public:
    std::string solve(std::string &str1, std::string &str2, int m, int n, std::vector<std::vector<std::string>> &dp) {
        if (m == 0 || n == 0) return "";
        if (dp[m][n] != "!") return dp[m][n];

        if (str1[m-1] == str2[n-1]) return dp[m][n] = solve(str1, str2, m-1, n-1, dp) + str1[m-1];
        std::string path1 = solve(str1, str2, m-1, n, dp);
        std::string path2 = solve(str1, str2, m, n-1, dp);

        return dp[m][n] = (path1.size() > path2.size()) ? path1 : path2;
    }

    std::string longestPalindrome(std::string str) {
        int m = str.size();
        std::string str1 = str;
        std::reverse(str1.begin(), str1.end());

        std::vector<std::vector<std::string>> dp(m+1, std::vector<std::string>(m+1, "!"));
        return solve(str, str1, m, m, dp);
    }
};

/**
 * Top Down
 * Time Complexity O((m*n * max(m, n)));
 */
class Solution {
public:
    std::string longestPalindrome(std::string str) {
        int m = str.size();
        std::string str1 = str;
        std::reverse(str1.begin(), str1.end());
        std::vector<std::vector<std::string>> dp(m+1, std::vector<std::string>(m+1, ""));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str[i-1] == str1[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + str[i-1];
                } else {
                    if (dp[i-1][j].size() > dp[i][j-1].size()) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][m];
    }
};

/**
 * Better Top - Down
 */

class Solution {
public:
    std::string longestPalindrome(std::string str1) {
        int m = str1.size();
        if (m == 0) return "";

        std::string str2 = str1;
        std::reverse(str1.begin(), str1.end());

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(m+1, 0));
        int maxLen = 0, endIdx = 0;
        // filling up the table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;

                    if (dp[i][j] > maxLen) {
                        if (m - j == i - dp[i][j]) {
                            maxLen = dp[i][j];
                            endIdx = i;
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return str1.substr(endIdx - maxLen, maxLen);
    }
};


class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() < 1) return "";
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            // Check odd length (center at i) and even length (center at i, i+1)
            for (int j : {0, 1}) {
                int l = i, r = i + j;
                while (l >= 0 && r < s.size() && s[l] == s[r]) {
                    if (r - l + 1 > maxLen) {
                        start = l;
                        maxLen = r - l + 1;
                    }
                    l--; r++;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};