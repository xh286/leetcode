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
    ListNode* swapPairs(ListNode* head) {
        // guard against trivial case, need at least 2 nodes
        if(!head || !head->next) return head;
        ListNode * new_head = head->next; // new head
        ListNode * next_p = head;
        
        ListNode * p = next_p;
        ListNode * p2 = p->next;
        ListNode * next_p = p2->next;
        
        while(next_p)
        {
            // modify
            p2->next = p;
            if(!next_p->next) //odd number of nodes, done
            {
                p->next = next_p;
                return new_head;
            }
            else
                p->next = next_p->next;
            // setup pointers
            p = next_p;
            p2 = p->next;
            next_p = p2->next;
        }
        // if even number of nodes, next_p is NULL here, and we have last two nodes left.
        p2->next = p;
        p->next = NULL;
        return new_head;
    }
};