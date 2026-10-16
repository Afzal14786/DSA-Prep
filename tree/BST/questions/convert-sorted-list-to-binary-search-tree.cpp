// رَبِّ زِدْنِي عِلْمًا
// اے میرے رب! میرے علم میں اضافہ فرما۔

// Question Link : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    /**
     * another solution approach 
     * @time complexity  : O(nlogn)
     * @space complexity : O(1)
     */
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode *slow_prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode *node = new TreeNode(slow->val);
        slow_prev->next = nullptr;
        node->left  = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);
        return node;
    }
};

class Solution {
public:
    /**
     * intial solution using extra space 
     * @timecomplexity : O(n) + O(n)
     * @space complexity : O(n)
     */
    TreeNode *solve(vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left  = solve(nums, start, mid-1);
        node->right = solve(nums, mid+1, end);
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // traverse over the linked list and generate an arrays
        ListNode *temp = head;
        vector<int> nums;
        while (temp != nullptr) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        // now we have the array, now generate an array
        return solve(nums, 0, nums.size() - 1);
    }
};

auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 'c';
}();