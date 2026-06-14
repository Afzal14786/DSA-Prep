// Question Link : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14

#include <iostream>
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

    void traverse(ListNode* head, ListNode* p, int &result, ListNode* &q) {
        if(p != nullptr) {
            q = head->next;
            traverse(head->next, p->next->next , result, q);
            if(head->val + q->val > result) {
                result = head->val + q->val;
            }
            q = q->next;
        }
    }

    int pairSum(ListNode* head) {
        if(head->next->next == nullptr){
            return head->val + head->next->val;
        }

        int result = 0;
        ListNode* p = head;
        ListNode* q = nullptr;
        traverse(head, p, result, q);
        return result;
    }
};
