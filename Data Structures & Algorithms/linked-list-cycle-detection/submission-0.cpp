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

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fp = head;
        while (fp) {
            if (fp->next) {
                if (fp->next->next) {
                    fp = fp->next->next;
                } else {
                    return false;
                }
            } else {
                return false;
            }
            if (fp == head) return true;
            head = head->next;
        }
        return false;
    }
};
