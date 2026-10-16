// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

/**
 * Optimize Code
 * @time complexity : O(height)
 * @space complexity : O(1)
 */

class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if (root == nullptr || k == nullptr) return -1;
        Node *successor = nullptr;

        while (root) {
            if (root->data <= k->data) root = root->right;
            else {
                successor = root;
                root = root->left;
            }
        }

        return (successor == nullptr) ? -1 : successor->data;
    }
};

/**
 * this is my initial thought after seeing the examples...
 * @time complexity : O(n) + O(n) = O(n)
 * @space complexity : O(n) for storing all the nodes
 */
class Solution {
public:
    void solve(Node *node, vector<Node*> &nums) {
        if (!node) return;
        solve(node->left, nums);
        nums.push_back(node);
        solve(node->right, nums);
    }

    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        if (!root || !k) return -1;
        vector<Node*> nums;
        solve(root, nums);
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                if (i+1 < n)
                    return nums[i+1]->data;
            }
        }

        return -1;
    }  
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();