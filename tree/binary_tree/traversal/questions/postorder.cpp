// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔
#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

// Question Link : https://leetcode.com/problems/binary-tree-postorder-traversal/
// Question Link : https://neetcode.io/problems/binary-tree-postorder-traversal/question?list=neetcode150

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode *temp = root;
        while (temp || !st.empty()) {
            // we know traverse left till we get the left side null
            if (temp) {
                st.push(temp);
                temp = temp->left;
            } else {
                // we fount the left's null
                // here in temp_node we are storing the stack's top's right node value
                TreeNode *temp_node = st.top()->right;
                if (temp_node == nullptr) {
                    // means this is the left node having zero number of children
                    // then now popped out the stack's top node and print it 
                    temp_node = st.top();
                    st.pop();

                    ans.push_back(temp_node->val);
                    
                    // also here we have to check the last visited value
                    while (!st.empty() && temp_node == st.top()->right) {
                        temp_node = st.top();
                        st.pop();
                        ans.push_back(temp_node->val);
                    }

                } else {
                    // means there is right child so move the temp_node to the right child
                    temp = temp_node;
                }
            }
        }

        return ans;
    }
};

int main() {
    
    return 0;
}