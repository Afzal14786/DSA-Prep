// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/problems/level-order-traversal-of-binary-tree/question?list=neetcode150
// Question Link : https://leetcode.com/problems/binary-tree-level-order-traversal/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            while (sz > 0) {
                TreeNode *curr_node = q.front();
                q.pop();

                temp.push_back(curr_node->val);

                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);
                sz--;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
