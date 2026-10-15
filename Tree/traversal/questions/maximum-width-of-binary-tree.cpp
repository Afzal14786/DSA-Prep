// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/maximum-width-of-binary-tree/description/
// Question Link : https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        ll max_width = 0;

        while (!q.empty()) {
            int n = q.size();
            ll L = q.front().second;
            ll R = q.back().second;
            max_width = max(max_width, R - L + 1);

            while (n--) {
                auto node = q.front();
                q.pop();

                if (node.first->left) q.push({node.first->left, node.second * 2 + 1});
                if (node.first->right) q.push({node.first->right, node.second * 2 + 2});
            }
        }

        return static_cast<int>(max_width);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();