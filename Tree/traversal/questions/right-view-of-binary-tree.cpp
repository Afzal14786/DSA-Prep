// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Question Link : https://neetcode.io/problems/binary-tree-right-side-view/question
// Question Link : https://leetcode.com/problems/binary-tree-right-side-view/

/*
Definition for Node */
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
    void solve(Node *root, int level, vector<int> &ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back(root->data);
        if (root->right) solve(root->right, level + 1, ans);
        if (root->left) solve(root->left, level + 1, ans);
    }

    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};


// leetcode solution 

class Solution {
public:
    void solve(TreeNode *root, int level, vector<int> &ans) {
        if (!root) return;
        if (level == ans.size()) ans.push_back(root->val);
        if (root->right) solve(root->right, level + 1, ans);
        if (root->left) solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};