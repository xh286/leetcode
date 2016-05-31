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
        // Trivial problem. Assume no cycles in either lists. Assume ascending. Could contain duplicates
        // guard against trivial cases
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* host_head = (l1->val <= l2->val)? l1 : l2;
        ListNode* guest_head = (l1->val <= l2->val)? l2 : l1;
        ListNode* p = host_head;  // pointer for host list
        ListNode* q = guest_head; // pointer for guest list
        // merge nodes in guest list into host list
        while(p->next && q) // if any pointer reaches NULL, that list is finished. Return.
        {
            if(p->next->val <= q->val)
            {
                p = p->next;
                continue;
            }
            // p->val <= q->val, and p->next->val > q->val. Move q as next of p.
            ListNode* p_next = p->next; // temporary copies of p->next and q->next before change
            ListNode* q_next = q->next;
            p->next = q;
            q->next = p_next; // change two next pointers to complete change.
            q = q_next; // q moves on to next node in its list
            p = p->next; // p points to newly merged node
        }
        // here, either p->next is NULL, p pointing to last node in its list. Or q is NULL, or guest list is empty.
        if(!p->next && q)
        {
            p->next = q;
        }
        return host_head;
    }
};