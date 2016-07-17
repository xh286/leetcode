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
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode *head, *tail;
        if(l1->val <= l2->val)
            {head=tail=l1;l1=l1->next;}
        else
            {head=tail=l2;l2=l2->next;}
        // keep collecting smaller node and splice after tail
        while(l1&&l2)
        {
            if(l1->val <= l2->val)
                {tail->next = l1; l1=l1->next;}
            else
                {tail->next = l2; l2=l2->next;}
            tail = tail->next;
        }
        if(!l1) tail->next = l2;
        if(!l2) tail->next = l1;
        return head;
    }
};