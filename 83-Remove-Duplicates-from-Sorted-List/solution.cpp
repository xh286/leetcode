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
    ListNode* deleteDuplicates(ListNode* head) {
        // Maintain 2 pointers, p and p_next, if p_next points to same value as p, then delete p_next.
        // Corner case: less than 2 nodes.
        if(!head) return head;
        ListNode* p = head;
        ListNode* p_next = head->next;
        while(p_next) // if p_next points to NULL, then stop
        {
            if(p_next->val == p->val)
            {
                // remove node pointed by p_next, p pointer unchanged, just p->next change. p_next pointer moves on.
                p->next = p_next->next;
                delete p_next;
                p_next = p->next;
            }
            else // no more duplicate for p->val, move p & p_next
            {
                p = p_next;
                p_next = p_next->next;
            }
        }
        return head;
    }
};