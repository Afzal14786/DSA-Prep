// Question Link : https://leetcode.com/problems/balance-a-binary-search-tree/submissions/1913260675/?envType=daily-question&envId=2026-02-09

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return helper(res, 0, res.size()-1);
    }

    void inorder(TreeNode* root, vector<int> &ans) {
        if (root != nullptr) {
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }


    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        int mid = start + (end - start)/2;
        TreeNode* curr_node = new TreeNode(nums[mid]);
        curr_node->left = helper(nums, start, mid-1);
        curr_node->right = helper(nums, mid+1, end);

        return curr_node;
    }
};
