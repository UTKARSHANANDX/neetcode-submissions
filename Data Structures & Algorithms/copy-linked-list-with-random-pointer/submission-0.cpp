/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        // Step 1: Insert cloned nodes after every original node
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Copy random pointers
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;

            curr = curr->next->next;
        }

        // Step 3: Separate the original and cloned lists
        curr = head;
        Node* clonedHead = head->next;
        Node* clone = clonedHead;

        while (curr) {
            curr->next = clone->next;
            curr = curr->next;

            if (curr) {
                clone->next = curr->next;
                clone = clone->next;
            }
        }

        return clonedHead;
    }
};