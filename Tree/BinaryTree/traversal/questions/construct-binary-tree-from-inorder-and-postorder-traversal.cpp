// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Question Link : https://neetcode.io/problems/construct-binary-tree-from-inorder-and-postorder-traversal/question

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode *solve(vector<int> &in, vector<int> &post, int inStart, int inEnd, int pStart, int pEnd) {
       if (inStart > inEnd) return nullptr;

        TreeNode *node = new TreeNode(post[pEnd]);
        int i = inStart;
        for (; i <= inEnd; ++i) {
            if (in[i] == node->val) break;
        }
        int left_size = i - inStart;
        int right_size = inEnd - i;

        node->left = solve(in, post, inStart, i-1, pStart, pStart + left_size - 1);
        node->right = solve(in, post, i+1, inEnd, pEnd - right_size, pEnd - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0, inEnd = n-1;
        int pStart = 0, pEnd = n-1;
        return solve(inorder, postorder, inStart, inEnd, pStart, pEnd);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();