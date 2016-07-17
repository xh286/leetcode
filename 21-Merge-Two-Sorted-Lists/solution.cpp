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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Iterative solution minimizing writes. Complex logic, cannot beat simpler, "less efficient" version.
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *host, *guest;
        if(l1->val <= l2->val)
            {host = l1; guest = l2;}
        else
            {host = l2; guest = l1;}
        ListNode *p = host, *q = guest;
        ListNode *p_next = p->next;
        ListNode *new_q;
        // Maintain invariant: find p & p_next pair that satisfy p->val <= q->val <= p_next->val.
        // Then q keep going until q->next->val > p->next->val, then new_q = q->next. And splice all q nodes between first q and last q inbetween p & p_next.
        // Requires valid p_next and q.
        while(p_next && q)
        {
            if(p_next->val < q->val)
            {p = p->next; p_next = p->next; continue;}
            p->next = q;
            while(q->next && q->next->val <= p_next->val) q = q->next;
            new_q = q->next;
            q->next = p_next;
            q = new_q;
        }
        if(!p_next) p->next = q;
        return host;
    }
};