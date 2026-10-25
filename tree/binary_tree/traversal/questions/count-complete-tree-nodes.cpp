// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/count-complete-tree-nodes/description/?envType=problem-list-v2&envId=tree

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;


/**
 * another solution
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int _left_depth  = left_depth(root);
        int _right_depth = right_depth(root);

        if (_left_depth == _right_depth) return (1 << _right_depth) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:

    int left_depth(TreeNode *node) {
        int depth = 0;
        while (node) {
            node = node->left;
            depth++;
        }
        return depth;
    }

    int right_depth(TreeNode *node) {
        int depth = 0;
        while (node) {
            node = node->right;
            depth++;
        }

        return depth;
    }
};


/**
 * a full binary tree can be a complete tree but a complete tree can not be a full binary tree
 * and a tree is complete is a full binary tree till the height - 1 and in the last level every node from left to right fills in an array without skipping any space
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int count = 0;
        while (!q.empty()) {
            int sz = q.size();
            count += sz;
            for (int i = 0; i < sz; ++i) {
                TreeNode *node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return count;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();