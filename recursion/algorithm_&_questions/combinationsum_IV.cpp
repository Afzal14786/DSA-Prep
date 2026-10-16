// Question Link : https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<vector<int>> &ans) {
    for (auto &nums : ans) {
        cout << "[";
        for (auto &x : nums) {
            cout << x << " ";
        }
        cout << "]";
        cout << endl;
    }
}

class Solution {
public:
    // recursion
    // int solve(vector<int> &nums, int target) {
    //     if (target == 0) {
    //         return 1;
    //     }

    //     if (target < 0) return 0;

    //     int count = 0;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         count += solve(nums, target - nums[i]);
    //     }

    //     return count;
    // }

    // memoization
    int solve(vector<int> &nums, int target, vector<int> &dp) {
        if (target == 0) return 1;
        if (dp[target] != -1) return dp[target];

        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (target >= nums[i]) {
                count += solve(nums, target - nums[i], dp);
            }
        }
        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
};

int main() {
    vector<int> nums = {1,2,3};
    int target = 4;
    Solution s;
    cout << "Total possible combiation : " << s.combinationSum4(nums, target) << endl;
    return 0;
}