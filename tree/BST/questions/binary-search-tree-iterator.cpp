// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/binary-search-tree-iterator/description/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

class BSTIterator { 
    stack<TreeNode*> st;
    void push_all(TreeNode *node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        push_all(root);
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        push_all(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();