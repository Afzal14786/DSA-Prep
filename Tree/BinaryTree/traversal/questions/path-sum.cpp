// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

// Question Link : https://leetcode.com/problems/path-sum/description/
// Question Link : https://neetcode.io/problems/path-sum/question?list=neetcode150

// Fast I/O block for LeetCode performance boost
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();

class Solution {
public:
    // TODO: Paste the specific LeetCode function declaration here (e.g., int twoSum(vector<int>& nums, int target))
    /**
     * @param root node
     * @param target integer
     * @return true/false
     *
     * @complexity
     *      - @time -  O(n)
     *      - @space - O(n)
     */
    static bool hasPathSum(const TreeNode* root, int target) {
        if (!root) return false;
        if (!root->left && !root->right) return target == 0;
        target -= root->val;

        return hasPathSum(root->left, target) || hasPathSum(root->right, target);
    }
};
