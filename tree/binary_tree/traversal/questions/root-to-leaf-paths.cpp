// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

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
    void solve(Node *node, vector<vector<int>> &ans, vector<int> &temp) {
        if (!node) return;
        if (!node->left && !node->right) {
            temp.push_back(node->data);
            ans.push_back(temp);
        }

        temp.push_back(node->data);
        solve(node->left, ans, temp);
        solve(node->right, ans, temp);

        temp.pop_back();
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, ans, temp);
        return ans;
    }
};