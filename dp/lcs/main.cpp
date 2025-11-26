#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int help(string s1, int n, string s2, int m) {
    if (n == 0 || m == 0) return 0;
    int ans = 0;

    if (s1[n-1] == s2[m-1]) {
        ans += 1 + help(s1, n-1, s2, m-1);
    } else {
        // there is two cases
        int case1 = help(s1, n-1, s2, m);
        int case2 = help(s1, n, s2, m-1);

        ans += max(case1, case2);
    }

    return ans;
}

// time complexity = O(2^n+m)
int longestCommonSubSequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // cout << "Size of the s1 is : " << n << " & size of the s2 is : " << m << endl;
    return help(s1, n, s2, m);
}

// way two
int lcsRec(string s1, string s2)  {
    int n = s1.size(), m = s2.size();

    if (n == 0 || m == 0) return 0;

    if (s1[n-1] == s2[m-1]) {
        return 1 + lcsRec(s1.substr(0, n-1), s2.substr(0, m-1));
    } else {
        int case1 = lcsRec(s1.substr(0, n-1), s2);
        int case2 = lcsRec(s1, s2.substr(0, m-1));
        return max(case1, case2);
    }
}

// memoization in LCS (Longest Common Subsequence)
// Time Complexity : O(n*m)
int lcsMemo(string s1, string s2, vector<vector<int>> &dp) {
    int n = s1.size(), m = s2.size();

    if (n == 0 || m == 0) return 0;

    if (dp[n][m] != -1) return dp[n][m];

    if (s1[n-1] == s2[m-1]) {
        dp[n][m] = 1 + lcsMemo(s1.substr(0, n-1), s2.substr(0, m-1), dp);
    } else {
        int case1 = lcsMemo(s1.substr(0, n-1), s2, dp);
        int case2 = lcsMemo(s1, s2.substr(0, m-1), dp);

        dp[n][m] = max(case1, case2);
    }

    return dp[n][m];
}

int lcsTabulation(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    if (n == 0 || m == 0) return 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // printing the table
    cout << "The DP Table : \n";
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][m];
}

int main() {
    string s1 = "abedge";
    string s2 = "abedg";

    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    cout << "Longest Common Subsequence : " << longestCommonSubSequence(s1, s2) << endl;
    cout << "Longest Common Subsequence : " << lcsRec(s1, s2) << endl;

    cout << "Longest Common Subsequence Using Memozation : " << lcsMemo(s1, s2, dp) << endl;

    cout << "Longest Common Subsequence Using Tabulation : " << lcsTabulation(s1, s2) << endl;
    return 0;
}