#include <iostream>
#include <vector>

using namespace std;

// Leetcode Link : https://leetcode.com/problems/unique-binary-search-trees/
// Solution Link : https://leetcode.com/problems/unique-binary-search-trees/submissions/1842172682/

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }

        return dp[n];
    }
};