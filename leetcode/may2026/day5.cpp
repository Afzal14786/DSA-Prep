// Question Link : https://leetcode.com/problems/rotate-list/submissions/1911363160/?envType=daily-question&envId=2026-05-05

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int cnt = 1;
        while (temp) {
            if (cnt == k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        ListNode *tail = head;
        int len = 1;
        while (tail->next) {
            len++;
            tail = tail->next;
        }

        if (k % len == 0) return head;
        k %= len;
        tail->next = head;
        ListNode* newLastNode = findNthNode(head, abs(len - k));
        head = newLastNode->next;
        newLastNode->next = nullptr;

        return head;
    }
};
