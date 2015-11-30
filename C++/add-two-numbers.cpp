/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
         ListNode *head = new ListNode(0);
        ListNode *p = head;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            int v1 = l1 == NULL ? 0 : l1->val;
            int v2 = l2 == NULL ? 0 : l2->val;
            int value = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;
            p -> next = new ListNode(value);
            p = p->next;
            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }
        if(carry)
            p -> next = new ListNode(carry);
        return head -> next;
    }
};
