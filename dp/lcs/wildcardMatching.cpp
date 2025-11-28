#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wildcardMatching(string text, string pattern) {
    int n = text.size(), m = pattern.size();

    if (n == 0 && m == 0) return true;

    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
        if (pattern[j-1] == '*') {
            dp[0][j] = dp[0][j-1];
        } else {
            dp[0][j] = false;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (text[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if (pattern[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

// Question Link : https://leetcode.com/problems/wildcard-matching/description/
// Submission Link : https://leetcode.com/problems/wildcard-matching/submissions/1842005342/


bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    dp[0][0] = true;

    for (int j = 1; j <= m; ++j) {
        if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
        else dp[0][j] = false;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else dp[i][j] = false;
        }
    }

    return dp[n][m];
}

int main() {
    string word = "abcd";
    string pattern = "*b*?";

    cout << (wildcardMatching(word, pattern) ? "Yes Matched\n" : "No, Not Matched\n");
    return 0;
}
