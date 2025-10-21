#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leetcode question : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/?envType=problem-list-v2&envId=breadth-first-search

/**
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[3],[20,9],[15,7]]
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>  result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();

                // let check the postion based on the direction
                int idx = leftToRight ? i : size - 1 - i;
                level[idx] = currNode->val;

                if (currNode->left != nullptr) q.push(currNode->left);
                if (currNode->right != nullptr) q.push(currNode->right);
            }
            result.push_back(level);
            leftToRight = !leftToRight; // toggle the direction
        }

        return result;
    }
};