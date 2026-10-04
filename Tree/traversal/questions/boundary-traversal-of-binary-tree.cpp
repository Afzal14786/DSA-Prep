// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

/* Node Structure */
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:

    bool isLeaf(Node *root) {
        if (!root) return false;
        return (!root->left && !root->right);
    }
    
    void traverse_left(Node *root, vector<int> &res) {
        // step 1: Traversing in the left
        Node *curr = root;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void traverse_leaf(Node *root, vector<int> &res) {
        // step 2 : traverse in the leaf nodes
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if (root->left) traverse_leaf(root->left, res);
        if (root->right) traverse_leaf(root->right, res);
    }

    void traverse_right(Node *root, vector<int> &res) {
        // step 3 : Traverse in the right subtree
        Node *curr = root;
        stack<int> st;

        while (curr) {
            if (!isLeaf(curr)) st.push(curr->data);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
    }

    vector<int> boundaryTraversal(Node *root) {
        // code here
        if (!root) return {};
        vector<int> res;

        if (!isLeaf(root)) res.push_back(root->data);
        traverse_left(root->left, res);
        traverse_leaf(root, res);
        traverse_right(root->right, res);

        return res;
    }
};