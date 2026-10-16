// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool getPath(TreeNode *root, vector<int> &arr, int k) {
        if (!root) return false;
        arr.push_back(root->val);

        if (root->val == k) return true;

        if (getPath(root->left, arr, k) || getPath(root->right, arr, k)) return true;

        arr.pop_back();
        return false;
    }

    vector<int> solve(TreeNode *root, int B) {
        vector<int> arr;
        if (!root) return arr;
        getPath(root, arr, B);
        return arr;
    }
};
