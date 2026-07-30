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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // edge cases - lists have no nodes
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* currNode = nullptr, *head = nullptr;

        while (list1 && list2) {
            ListNode* nextNode;
            if (list1->val <= list2->val) {
                nextNode = list1;
                list1 = list1->next;
            } else {
                nextNode = list2;
                list2 = list2->next;
            }
            
            if (!head) {
                head = nextNode;
                currNode = head;
            } else {
                currNode->next = nextNode;
                currNode = currNode->next;
            }
        }

        if (list1) {
            currNode->next = list1;
        } else if (list2) {
            currNode->next = list2;
        }

        return head;
    }
};