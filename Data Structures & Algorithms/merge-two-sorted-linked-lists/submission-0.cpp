class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        ListNode* l1 = list1;
        ListNode* l2 = list2;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        while(l1 != nullptr){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }

        while(l2 != nullptr){
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }

        return ans->next;
    }
};
