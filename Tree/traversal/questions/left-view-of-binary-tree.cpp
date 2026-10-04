// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

/* Structure of Binary Tree Node */
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
        if (root->left) solve(root->left, level + 1, ans);
        if (root->right) solve(root->right, level + 1, ans);
    }

    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};