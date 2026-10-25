// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link :https://leetcode.com/problems/path-sum-ii/description/?envType=problem-list-v2&envId=tree

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, vector<int> &temp, vector<vector<int>> &ans, int target_sum, int curr_sum) {
        if (!node) return;
        curr_sum += node->val;

        temp.push_back(node->val);
        if (!node->left && !node->right && curr_sum == target_sum) ans.push_back(temp);
        
        solve(node->left, temp, ans, target_sum, curr_sum);
        solve(node->right, temp, ans, target_sum, curr_sum);
        
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target_sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, temp, ans, target_sum, 0);
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();