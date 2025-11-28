#include <iostream>
#include <vector>
#include <string>

using namespace std;

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