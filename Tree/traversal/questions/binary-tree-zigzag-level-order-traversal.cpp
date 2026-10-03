// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
// Question Link : https://neetcode.io/problems/binary-tree-zigzag-level-order-traversal/question
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        vector<vector<int>> ans;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size);

            for (int i = 0; i < size; ++i) {
                TreeNode *t = q.front();
                q.pop();

                int idx = (flag) ? i : (size - 1 - i);
                temp[idx] = t->val;

                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }

            flag = !flag;
            ans.push_back(temp);
        }

        return ans;
    }
};