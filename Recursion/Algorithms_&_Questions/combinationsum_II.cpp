// Question Link : https://leetcode.com/problems/combination-sum-ii/

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

    void solve(vector<int> &candidates, int target, int start, vector<int> &temp, vector<vector<int>> &ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break;
            if (i > start && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, 0, temp, ans);  
        return ans;    
    }
};

int main() {
    Solution s;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = s.combinationSum2(nums, target);
    print(ans);
    return 0;
}