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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        // reverse a linked list with a stack
        stack<ListNode*> s;
        ListNode* p = head;
        while(p)
        {
            s.push(p);
            p = p->next;
        }
        // p is NULL here. stack top is end of linked list.
        ListNode* new_head = s.top();
        p = new_head;
        s.pop();
        while(!s.empty())
        {
            p->next = s.top();
            p = p->next;
            s.pop();
        }
        p->next = NULL;
        return new_head;
    }
};