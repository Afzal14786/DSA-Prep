#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// leetcode question link : https://leetcode.com/problems/binary-tree-level-order-traversal/description/?envType=problem-list-v2&envId=breadth-first-search

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // get the size of the current level
            int size = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < size; ++i) {
                TreeNode* currNode = q.front();
                q.pop();

                currentLevel.push_back(currNode->val);


                if (currNode->left != nullptr) {
                    q.push(currNode->left);
                }
                
                if (currNode->right != nullptr) {
                    q.push(currNode->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};

int main() {
    vector<int> graph = {3,9,20,0,0,15,7};
    return 0;
}