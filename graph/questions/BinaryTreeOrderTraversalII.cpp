#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leetcode question : https://leetcode.com/problems/binary-tree-level-order-traversal-ii?envType=problem-list-v2&envId=breadth-first-search

/**
 * Input: root = [3,9,20,null,null,15,7]
 * Output: [[15,7],[9,20],[3]]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;

        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();

                level.push_back(currNode->val);

                if (currNode->left != nullptr) q.push(currNode->left);
                if (currNode->right != nullptr) q.push(currNode->right);
            }

            result.push_back(level);
        }
        // now reverse the result here
        reverse(result.begin(), result.end());
        return result;
    }
};

