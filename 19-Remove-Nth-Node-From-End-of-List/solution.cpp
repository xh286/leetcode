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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // naive solution: reverse list, remove nth, then reverse back.
        // Or, count total nodes m, then start over and remove (m-n)th.
        // One-pass: maintain a pointer that's n steps ahead of head, then move until this pointer hits NULL.
        // Example: m = 5 nodes, so total 5 edges, including last one pointing to NULL. n = 4, means 2nd node from left, or just 1 step from head. Initially, p1 points to head (1st node), and p2 points to 5th node. Then we find p2->next is NULL, so we remove p1->next;
        if(!head) return NULL;
        if(n <= 0) return head;
        ListNode* p1 = head;
        ListNode* p2 = p1;
        for(int i=0; i<n; i++)
        {
            if(p2)
                p2 = p2->next;
            else
                return head; // n > number of nodes in list, return without change
        }
        if(!p2) // need to remove head
        {
            ListNode* p_free = head;
            head = head->next;
            free(p_free);
            return head;
        }
        // Otherwise remove p1->next. But go until p2->next is NULL.
        while(p2->next)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        ListNode* p_free = p1->next;
        p1->next = p1->next->next;
        free(p_free);
        return head;
    }
};