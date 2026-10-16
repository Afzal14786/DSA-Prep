// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question List : https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};


class Solution {
public:
    void solve(Node *node, vector<Node*> &nodes) {
        if (!node) return;
        solve(node->left, nodes);
        nodes.push_back(node);
        solve(node->right, nodes);
    }

    Node *flattenBST(Node *root) {
        // code here
        if (!root) return nullptr;
        vector<Node*> nodes;
        solve(root, nodes);

        int n = nodes.size();
        for (int i = 0; i < n; ++i) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i+1];
        }

        nodes[n-1]->left = nullptr;
        nodes[n-1]->right = nullptr;

        return nodes[0];
    }
    
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();