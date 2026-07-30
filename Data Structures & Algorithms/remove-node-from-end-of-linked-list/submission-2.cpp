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
        if (head == nullptr) return head;
        int length = 0;
        // want to store length we can get position of node to remove
        for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            length++;
        }

        // position from start = length - start + 1 from end
        int posFromStart = length - n;
        ListNode* prevNode = nullptr;
        ListNode* currNode = head;

        while (posFromStart > 0) {
            prevNode = currNode;
            currNode = currNode->next;
            posFromStart--;
        }

        if (currNode == nullptr) {
        } else if (currNode) {
            if (currNode == head) {
                head = head->next;
            } else {
                prevNode->next = currNode->next;
            }
        }

        return head;



    }
};
