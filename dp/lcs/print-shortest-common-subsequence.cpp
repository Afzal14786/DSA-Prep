// Question Link : https://leetcode.com/problems/shortest-common-supersequence/description/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string shortestCommonSupersequence(std::string str1, std::string str2) {
        int m = str1.size(), n = str2.size();

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

        // fill up the table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == 0) dp[i][j] = j;
                else if (j == 0) dp[i][j] = i;
                else if (str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 1 + std::min(dp[i-1][j], dp[i][j-1]);
            }
        }

        // now forming the result
        std::string ans = "";
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            } else if (dp[i-1][j] < dp[i][j-1]) {
                ans.push_back(str1[i-1]);
                i--;
            } else {
                ans.push_back(str2[j-1]);
                j--;
            }
        } 

        // now remaining answer
        while (i > 0) {
            ans.push_back(str1[i-1]);
            i--;
        }

        while (j > 0) {
            ans.push_back(str2[j-1]);
            j--;
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};