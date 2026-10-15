// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/problems/binary-tree-inorder-traversal/question?list=neetcode150
// Question Link : https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode *temp = root;

        while (temp || !st.empty()) {
            if (temp) {
                st.push(temp);
                temp = temp->left;
            } else {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                temp = temp->right;
            }
        }

        return ans;
    }
};