#include <iostream>
#include <vector>
#include <queue>

// leet code question link : https://leetcode.com/problems/minimum-depth-of-binary-tree/submissions/1807668638/?envType=problem-list-v2&envId=breadth-first-search

using namespace std;

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
    int minDepth(TreeNode *root) {

        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int depth = 1;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                // take the currNode'
                TreeNode *currNode = q.front(); q.pop();

                if (currNode->left == nullptr && currNode->right == nullptr) return depth;

                // if not then add the childs into the queue
                if (currNode->left != nullptr) q.push(currNode->left);
                if (currNode->right != nullptr) q.push(currNode->right);
            }
            depth++;
        }

        return depth;
    }
};