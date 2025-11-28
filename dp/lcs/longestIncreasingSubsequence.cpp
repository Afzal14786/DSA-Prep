#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int help(vector<int> nums, vector<int> temp) {
    int n = nums.size(), m = temp.size();
    if (n == 0 || m == 0) return 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (nums[i-1] == temp[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int lengthOfLIS(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    vector<int> temp(s.begin(), s.end());
    sort(temp.begin(), temp.end());
    
    return help(nums, temp);
}

int lengthOfLIS2(vector<int>& nums) {
    vector<int> dp;
    for (int x : nums) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end())
            dp.push_back(x);
        else
            *it = x;
    }
    return dp.size();
}

// leetcode question : https://leetcode.com/problems/longest-increasing-subsequence/submissions/1841745945/

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << "Maximum Increasing Common Length Is : " << lengthOfLIS(nums) << endl;
    return 0;
}