/**
 * Maximum Product Of Splitted Binary Tree
 * Question Link : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/?envType=daily-question&envId=2026-01-07
 * Solution Link : https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/submissions/1877260683/?envType=daily-question&envId=2026-01-07
 */

// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
// Note that you need to maximize the answer before taking the mod and not after taking it.

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

// Example 2:

// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

// Constraints:
//  The number of nodes in the tree is in the range [2, 5 * 104].
//  1 <= Node.val <= 104


#include <iostream>
#include <queue>
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
    const int MOD = 1e9 + 7;
    vector<long long> sum;

    long long dfs(TreeNode *node) {
        if (!node) return 0;

        long long s = node->val + dfs(node->left) + dfs(node->right);
        sum.push_back(s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long ans = 0;
        for (long long x : sum) {
            ans = max(ans, x * (total - x));
        }

        return ans % MOD;
    }
};