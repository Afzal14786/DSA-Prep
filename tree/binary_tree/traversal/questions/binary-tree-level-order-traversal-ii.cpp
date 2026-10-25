// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/?envType=problem-list-v2&envId=tree

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> vec;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front(); q.pop();
                temp.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            vec.push_back(temp);
        }

        reverse(vec.begin(), vec.end());
        return vec;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();