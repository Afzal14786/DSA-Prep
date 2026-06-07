// Question Link : https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2026-06-07

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


//  Definition for a binary tree node.
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int size = descriptions.size();
        unordered_map<int, TreeNode*> nodes;
        nodes.reserve(size + 1);
        int root = 0;

        for (auto &d : descriptions) {
            int x = d[0], y = d[1], isLeft = d[2];
            if (!nodes.contains(x)) {
                nodes[x] = new TreeNode(x);
                root ^= x;
            }

            if (!nodes.contains(y)) {
                nodes[y] = new TreeNode(y);
                root ^= y;
            }

            if (isLeft) nodes[x]->left = nodes[y];
            else nodes[x]->right = nodes[y];

            root ^= y;
        }

        return nodes[root];
    }
};