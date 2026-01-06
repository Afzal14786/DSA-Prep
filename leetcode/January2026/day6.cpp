/**
 * Maximum Level Sum Of A Binary Tree
 * Question Link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06
 * Solution Link : https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/1876048412/?envType=daily-question&envId=2026-01-06
 */

// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

// Example 1:

// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.

// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// -10^5 <= Node.val <= 10^5

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <climits>

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
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);

        int max_sum = INT_MIN;
        int curr_level = 1, max_level = 1;

        while (!q.empty()) {
            long long curr_size = q.size();       // calculate the curr_level size, 
            long long curr_level_sum = 0;   // calculate the curr_level sum

            for (int i = 0; i < curr_size; ++i) {
                TreeNode *curr_node = q.front();
                q.pop();

                curr_level_sum += curr_node->val;

                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);
            }

            if (curr_level_sum > max_sum) {
                max_sum = curr_level_sum;
                max_level = curr_level;
            }

            curr_level++;
        }

        return max_level;
    }
};


// another solution :


class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        vector<long long> levelSum;
        queue<TreeNode*> q;
        q.push(root);

        long long max_sum = INT_MIN;

        while (!q.empty()) {
            int curr_size = q.size();

            for (int i = 0; i < curr_size; ++i) {
                TreeNode *curr_node = q.front();
                q.pop();

                max_sum += curr_node->val;

                if (curr_node->left) q.push(curr_node->left);
                if (curr_node->right) q.push(curr_node->right);
            }

            levelSum.push_back(max_sum);
            max_sum = 0;
        }

        return max_element(levelSum.begin(), levelSum.end()) - levelSum.begin() + 1;
    }
};