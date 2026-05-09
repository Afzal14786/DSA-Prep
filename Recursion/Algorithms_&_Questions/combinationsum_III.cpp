// Question Link : https://leetcode.com/problems/combination-sum-iii/

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
    void solve(vector<int> &nums, int count, int target, int start, vector<int> &temp, vector<vector<int>> &ans) {
        if (count == 0 && target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > target) break;
            if (i > start && nums[i] == nums[i-1]) continue;

            count--;
            temp.push_back(nums[i]);
            solve(nums, count, target - nums[i], i+1, temp, ans);
            temp.pop_back();
            count++;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {  // k = count & n = target
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;

        solve(nums, k, n, 0, temp, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> ans = s.combinationSum3(3, 7);
    print(ans);
    return 0;
}