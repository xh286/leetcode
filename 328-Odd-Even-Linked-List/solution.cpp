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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode * p1 =  head;
        ListNode * p2 = head->next;
        ListNode * p1_head = p1;
        ListNode * p2_head = p2;
        bool mod_odd = true;
        while(p1 && p2)
        {
            if(mod_odd)
            {
                if(!p2->next)
                {
                    p1->next = p2_head; // done
                    break;
                }
                else
                {
                    p1->next = p2->next;
                    p1 = p2->next;
                    mod_odd = false;
                }
            }
            else
            {
                if(!p1->next)
                {
                    p2->next = NULL;
                    p1->next = p2_head;
                    break;
                }
                else
                {
                    p2->next = p1->next;
                    p2 = p1->next;
                    mod_odd = true;
                }
            }
        }
        return p1_head;
    }
};