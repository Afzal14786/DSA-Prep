// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
// Question Link : https://www.geeksforgeeks.org/problems/max-level-sum-in-binary-tree/1

class Solution {
public:
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int max_sum = INT_MIN;
        int curr_level = 1 ans_level = 0;
        pair<int, int> p;
        while (!q.empty()) {
            int sz = q.size();
            int curr_sum = 0;
            while (sz > 0) {
                TreeNode *temp = q.front();
                q.pop();
                curr_sum += temp->val;
                max_sum = max(max_sum, curr_sum);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                sz--;
            }
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                ans_level = curr_level;
            }
            curr_level++;
        }

        return ans_level;
    }
};

// Fast I/O block for LeetCode performance boost
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();