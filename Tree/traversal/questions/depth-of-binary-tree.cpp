// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://neetcode.io/problems/depth-of-binary-tree/question?list=neetcode150
// Question Link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/**
 * Optimize Code
 */


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};


// brute force using q and maintain a count
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz > 0) {
                TreeNode *temp = q.front();
                q.pop();

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);

                sz--;
            }
            level++;
        }
        return level;
    }
};

int main() {
    
    return 0;
}