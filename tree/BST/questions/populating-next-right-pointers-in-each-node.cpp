// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Question Link : https://neetcode.io/problems/populating-next-right-pointers-in-each-node/question

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root;
        Node *prev = nullptr;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);

        while (!q.empty()) {
            Node *node = q.front();
            q.pop();

            if (node != nullptr) {
                if (prev != nullptr) {
                    prev->next = node;
                }
                prev = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            } else {
                prev = nullptr;
                if (!q.empty()) q.push(nullptr);
            }
        }

        return root;
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();