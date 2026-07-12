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
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        // reverse so "n from end" becomes "n from front"
        head = reverseLL(head);

        // remove nth node from the front
        if (n == 1) {
            ListNode* newHead = head->next;
            delete head;
            head = newHead;
        } else {
            ListNode* curr = head;
            for (int i = 1; i < n - 1; i++) {
                curr = curr->next;
            }
            // curr points to (n-1)th node
            ListNode* toDelete = curr->next;
            curr->next = toDelete->next;
            delete toDelete;
        }

        // reverse back
        head = reverseLL(head);
        return head;
    }
};
