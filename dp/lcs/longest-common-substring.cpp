#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/longest-common-substring1452/1

/**
 * Recursion Code 
 */

class Solution {
  public:
    int solve(string &s1, string &s2, int m, int n, int count) {
        // base case 
        if (m == 0 || n == 0) return count;
        int match = count;
        if (s1[m-1] == s2[n-1]) return count = solve(s1, s2, m-1, n-1, count+1);
        int branch1 = solve(s1, s2, m-1, n, 0);
        int branch2 = solve(s1, s2, m, n-1, 0);

        return std::max({match, branch1, branch2});
    }

    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m = s1.size(), n = s2.size();
        return solve(s1, s2, m, n, 0);
    }
};

/**
 * Memoization
 */

class Solution {
  public:
    int solve(string &s1, string &s2, int m, int n, int &max_len, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];

        solve(s1, s2, m-1, n, max_len, dp);
        solve(s1, s2, m, n-1, max_len, dp);

        if (s1[m-1] == s2[n-1]) {
            int curr_suffix = 1 + solve(s1, s2, m-1, n-1, max_len, dp);
            max_len = max(max_len, curr_suffix);
            return dp[m][n] = curr_suffix;
        }
        
        return dp[m][n] = 0;
    }

    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m = s1.size(), n = s2.size();
        int max_len = 0;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        solve(s1, s2, m, n, max_len, dp);
        return max_len;
    }
};

/**
 * Top - Down Approach
 */

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[m][n];
    }
};

int longestCommonSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    if (n == 0 || m == 0) return 0;
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

// Question Link : https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Leetcode : 718

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();

    if (n == 0 || m == 0) return 0;
    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (nums1[i-1] == nums2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main() {
    string s1 = "12321";
    string s2 = "32147";

    cout << "Longest Common Substring : " << longestCommonSubstring(s1, s2) << endl;

    vector<int> n1 = {0,0,0,0,0};
    vector<int> n2 = {0,0,0,0,0};

    cout << "Longest Commen Length In THe Given Arrays is : " << findLength(n1, n2) << endl;
    return 0;
}