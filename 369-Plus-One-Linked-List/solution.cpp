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
    ListNode* plusOne(ListNode* head) {
        // Expensive solution is to reverse list, add 1, then reverse back.
        // Smart solution: track last non-9 node (pn9), increment that node, then set rest (if any) to zeros.
        // Example: 0 -> 1. 999 (pn9 NULL) -> 1000. 899 (pn9->8) -> 900. 
        ListNode* pn9 = NULL;
        for(ListNode* p = head; p != NULL; p=p->next)
        {
            if(p->val != 9)
                pn9 = p;
        }
        // if head is NULL, or entire list is 9...9, then pn9 = NULL. Need create new node.
        if(pn9 == NULL)
        {
            pn9 = new ListNode(1);
            pn9->next = head;
            head = pn9;
        }
        else // pn9 points to a non-9 node. Just increment 1.
        {
            pn9->val += 1;
        }
        for(ListNode *p = pn9->next; p != NULL; p = p->next)
        {
            p->val = 0;
        }
        return head;
    }
};