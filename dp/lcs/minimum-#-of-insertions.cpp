// Question Link (Leetcode): https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Question Link (GFG): https://www.geeksforgeeks.org/problems/form-a-palindrome2544/1
// Question Link (Code 360): https://www.naukri.com/code360/problems/minimum-insertions-to-make-a-string-palindrome_985293?leftPanelTabValue=SUBMISSION

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// leetcode
class Solution {
public:
    int minInsertions(std::string s) {
        int m = s.size();
        std::string s2 = s;
        std::reverse(s2.begin(), s2.end());
        std::vector<std::vector<int>> dp(m+1, std::vector<int>(m+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // more optimize ~ Two different arrays
        std::vector<int> prev(m+1, 0), curr(m+1, 0);
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == s2[j-1]) curr[j] = prev[j-1] + 1;
                else curr[j] = std::max(curr[j-1], prev[j]);
            }
            prev = curr;
        }

        // return m - dp[m][m];
        return m - prev[m];
    }
};

// gfg
class Solution {
  public:
    int findMinInsertions(std::string &s) {
        // code here
        int m = s.size();
        std::string s2 = s;
        std::reverse(s2.begin(), s2.end());

        std::vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = std::max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return m - prev[m];
    }
};

class Solution {
  public:
    int findMinInsertions(std::string &s) {
        int m = s.size();
        std::string s2 = s;
        std::reverse(s2.begin(), s2.end());

        std::vector<int> dp(m+1, 0);
        for (int i = 1; i <= m; ++i) {
            int diag = 0;
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                if (s[i-1] == s2[j-1]) dp[j] = 1 + diag;
                else dp[j] = std::max(dp[j], dp[j-1]);
                diag = temp;
            }
        }

        return m - dp[m];
    }
};