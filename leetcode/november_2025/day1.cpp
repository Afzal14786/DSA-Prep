
/** Day 1: Leetcode Question no 3217 Delete nodes from linkedlist present in Array */

// You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.

// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
// Explanation:
// Remove the nodes with values 1, 2, and 3.

// Input: nums = [1], head = [1,2,1,2,1,2]
// Output: [2,2,2]
// Explanation:
// Remove the nodes with value 1.

// Example 3:

// Input: nums = [5], head = [1,2,3,4]
// Output: [1,2,3,4]
// Explanation:
// No node has value 5.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(), nums.end());

        while (head != nullptr && toRemove.count(head->val)) {
            head = head->next;
        }

        if (head == nullptr) return nullptr;

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != nullptr) {
            if (toRemove.count(curr->val)) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};

/**
 * Practive Two Sum
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (temp.find(comp) != temp.end()) {
                ans.push_back(temp[comp]);
                ans.push_back(i);

                return ans;
            }

            temp[nums[i]] = i;
        }

        return {-1, -1};
    }
};