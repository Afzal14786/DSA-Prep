#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Question Link : https://leetcode.com/problems/edit-distance/

int minDistance(string word1, string word2) {
    int n = word1.size(), m= word2.size();

    if (n == 0) return m;
    if (m == 0) return n;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i-1] == word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
            else dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
        }
    }

    return dp[n][m] + 1;
}

int minDistance2(string word1, string word2) {
    int n = word1.size(), m= word2.size();

    if (n == 0 && m == 0) return 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));


    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (word1[i-1] == word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
            else dp[i][j] = 1 + min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
        }
    }

    return dp[n][m];
}


int main() {
    string s1 = "intention";
    string s2 = "execution";

    cout << "Minimum No Of Operations is : " << minDistance(s1, s2) << endl;
    return 0;
}