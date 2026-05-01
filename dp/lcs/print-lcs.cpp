
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>

// Time Complexity: (O(2^max(m, n)} * min(m, n)))
// Space Complexity: (O((m + n) * min(m, n)))
class Solution {
public:
    std::string solve(std::string &s1, std::string &s2, int m, int n) {
        // base case
        if (m == 0 || n == 0) return "";
        if (s1[m-1] == s2[n-1]) {
            return solve(s1, s2, m-1, n-1) + s1[m-1];
        }

        // what if the characters are not same then ??
        std::string res1 = solve(s1, s2, m-1, n);
        std::string res2 = solve(s1, s2, m, n-1);

        return (res1.size() > res2.size()) ? res1 : res2;
    }

    std::string printLCS(std::string &s1, std::string &s2) {
        int m = s1.size(), n = s2.size(); 
        return solve(s1, s2, m, n);
    }
};

// memoization
// 1. Time Complexity: (O(m * n * min(m, n)))
// 2. Space Complexity: (O(m * n * min(m, n)))

class Memoization {
public:
    std::string solve(std::string &s1, std::string &s2, int m, int n, std::vector<std::vector<std::string>> &dp) {
        // base case
        if (m == 0 || n == 0) return "";
        if (dp[m][n] != "") return dp[m][n];

        if (s1[m-1] == s2[n-1]) {
            return dp[m][n] = solve(s1, s2, m-1, n-1, dp) + s1[m-1];
        }

        // what if the characters are not same then ??
        std::string res1 = solve(s1, s2, m-1, n, dp);
        std::string res2 = solve(s1, s2, m, n-1, dp);

        return dp[m][n] = (res1.size() > res2.size()) ? res1 : res2;
    }

    std::string printLCS(std::string &s1, std::string &s2) {
        int m = s1.size(), n = s2.size(); 
        std::vector<std::vector<std::string>> dp(m+1, std::vector<std::string>(n+1, "!"));
        return solve(s1, s2, m, n, dp);
    }
};

// top - down approach 
// 1. Time Complexity: (O(m * n * min(m, n)))
// 2. Space Complexity: (O(m * n * min(m, n)))
class TopDown {
public:

    std::string printLCS(std::string &s1, std::string &s2) {
        int m = s1.size(), n = s2.size(); 
        std::vector<std::vector<std::string>> dp(m+1, std::vector<std::string>(n+1, ""));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                } else {
                    if (dp[i-1][j].size() > dp[i][j-1].size()) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }

        return dp[m][n];
    }
};

class BetterApproach {
public:
    std::string printLCS(std::string &s1, std::string &s2) {
        int m = s1.size(), n = s2.size();
        // now first fill the table
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // now traverse back in the dp and find out the answer
        std::string ans = "";
        int i = m, j = n;

        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    BetterApproach s;
    std::string s1, s2;
    std::cout << "Enter S1: ";
    std::cin >> s1;

    std::cout << "Enter S2: ";
    std::cin >> s2;

    std::cout << "Longest Commong Subsequence Of " << s1 << " & " << s2 << " is : " << s.printLCS(s1, s2) << std::endl;
    return 0;
}