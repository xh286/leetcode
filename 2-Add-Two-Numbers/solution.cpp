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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return NULL;
        ListNode* head;
        ListNode* pre;
        ListNode* p;
        // Edge case: return zero if sum is zero. Create first node anyway!
        int a = 0, b = 0, c = 0;
        bool first_node = true;
        do{
            
            a = (l1!=NULL)?l1->val:0;
            b = (l2!=NULL)?l2->val:0;
            int sum = a+b+c;
            p = new ListNode(sum%10);
            if(first_node)
            {
                head = p;
                first_node = false;
            }
            else
            {
                pre->next = p;
            }
            pre = p;
            c = (sum>=10)?1:0;
            if(l1) l1 = l1->next; // easy to miss the if condition here.
            if(l2) l2 = l2->next;
        }while(l1!=NULL || l2!=NULL || c!=0);
        return head;
    }
};