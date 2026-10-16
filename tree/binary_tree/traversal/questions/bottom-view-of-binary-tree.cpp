// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/* Definition for Node */

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
    vector<int> bottomView(Node *root) {
        // code here
        if (!root) return {};
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            Node *node = t.first;
            int line = t.second;

            if (mpp.find(line) != mpp.end()) mpp[line] = node->data;
            else mpp[line] = node->data;
            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        vector<int> ans;
        for (auto p : mpp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};