#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// leetcode question link: https://leetcode.com/problems/symmetric-tree/?envType=problem-list-v2&envId=breadth-first-search

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// using breadth first search
// this solution is not optimize
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode *leftNode = q.front(); q.pop();
            TreeNode *rightNode = q.front(); q.pop();

            // check the conditions
            if (leftNode == nullptr && rightNode == nullptr) return true;
            if (leftNode == nullptr || rightNode == nullptr) return false;
            if (leftNode->val !=  rightNode->val) return false;

            // now push the childs into the queue in mirror order
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        return true;
    }
};

// using depth first search
// this is the optimize solution for the qiven question 
class Solution2 {
public:
    bool isSymmetric2(TreeNode* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* left, TreeNode* right) {
        if (left == nullptr || right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val) return false;

        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};