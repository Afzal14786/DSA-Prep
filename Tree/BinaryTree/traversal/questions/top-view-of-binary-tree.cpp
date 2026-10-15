// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if (!root) return {};
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int line = p.second;

            if (mpp.find(line) == mpp.end()) mpp[line] = node->data;

            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        vector<int> ans;
        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};