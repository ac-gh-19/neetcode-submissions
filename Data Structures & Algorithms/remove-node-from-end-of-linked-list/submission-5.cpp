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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        recurse(dummy, head, n);
        return dummy->next;
    }

    int recurse(ListNode* prev, ListNode* curr, int n) {
        if (curr == nullptr) {
            return 1;
        }

        int place = recurse(curr, curr->next, n);
        if (place == n) {
            prev->next = curr->next;
        }

        return 1 + place;
    }

};
