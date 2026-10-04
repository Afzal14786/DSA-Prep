// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;



// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Question Link : https://leetcode.com/problems/diameter-of-binary-tree/description/
// Question Link : https://neetcode.io/problems/binary-tree-diameter/question?list=neetcode150 

class Solution {
public:

    int height(TreeNode *root, int &diameter) {
        if (!root) return 0;
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};


/* Structure of binary tree Node */

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    int solve(Node *root, int &ans) {
        if (!root) return 0;

        int l = solve(root->left, ans);
        int r = solve(root->right, ans);

        ans = max(ans, 1 + l + r);

        return 1 + max(l, r);
    }

    int diameter(Node* root) {
        // code here
        int ans = 0;
        solve(root, ans);
        return ans - 1;
    }
};