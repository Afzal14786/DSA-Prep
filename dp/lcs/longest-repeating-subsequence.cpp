// Question Link : https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

#include <iostream>
#include <vector>

class Solution {
  public:
    int LongestRepeatingSubsequence(std::string &s) {
        // Code here
        int m = s.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(m+1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == s[j-1] && i != j) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][m];
    }
};

class Solution {
public:
    int longestRepeatingSubsequence(std::string s1) {
        std::string str1 = s1, str2 = s1;

        int m = s1.size();
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(m+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (str1[i-1] == str2[j-1] && i != j) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][m];
    }
};


int main() {
    std::string str1 = "AABEBCDD";
    Solution s1;
    std::cout << "Longest Repeating Subsequence : " << s1.longestRepeatingSubsequence(str1) << std::endl;
    return 0;
}