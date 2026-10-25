// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=problem-list-v2&envId=tree

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    void solve(TreeNode *node, string num, int &ans) {
        if (!node) return;
        num.push_back(node->val + '0');
        
        // the moment pointer reach at the leaf node, compute the anser
        if (!node->left && !node->right) {
            // means this is the last node
            ans += stoi(num);
            return;
        }

        solve(node->left, num, ans);
        solve(node->right, num, ans);
        num.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        int ans = 0;
        if (!root) return ans;
        solve(root, "", ans);
        return ans;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();