#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool sequencePatternMatching(std::string s1, std::string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;

        std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return (dp[m][n] == m);
    }
};

int main() {
    std::string s1, s2;
    std::cout << "Enter string 1 & 2 : ";
    std::cin >> s1 >> s2;

    Solution s;
    if (s.sequencePatternMatching(s1, s2)) {
        std::cout << "Yes Pattern is matching.\n";
    } else {
        std::cout << "No, pattern is not matching.\n";
    }

    return 0;
}