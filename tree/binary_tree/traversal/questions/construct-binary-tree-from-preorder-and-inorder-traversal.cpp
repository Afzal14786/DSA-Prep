// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/problems/binary-tree-from-preorder-and-inorder-traversal/question
// Question Link : leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

class Solution {
public:

    TreeNode *solve(vector<int> &pre, vector<int> &in, int start, int end, int &idx) {
        if (start > end) return nullptr;
        int root_val = pre[idx];
        int i = start;
        for (; i <= end; ++i) {
            if (in[i] == root_val) break;
        }
        idx++;
        TreeNode *node = new TreeNode(root_val);
        // now go left and right
        node->left = solve(pre, in, start, i-1, idx);
        node->right = solve(pre, in, i+1, end, idx);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n-1, idx);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();
