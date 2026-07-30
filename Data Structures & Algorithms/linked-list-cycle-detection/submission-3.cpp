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
        if (!head) return false;
        ListNode* fp = head;
        while (head) {
            if (!fp->next || !fp->next->next) return false;
            fp = fp->next->next;
            if (head == fp) return true;
            head = head->next;
        }

    }
};
