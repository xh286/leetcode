/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseLinkedList(ListNode* head) // reverse a linked list without a stack; return new head
    {
        ListNode* p0 = NULL;
        ListNode* p1 = head;
        if(!head) return NULL; // empty list
        ListNode* p2 = p1->next;
        if(!p2) return head; // single node
        while(p2)
        {
            p1->next = p0;
            p0 = p1;
            p1 = p2;
            if(p2)
            {
                p2 = p2->next;
            }
            else // p2 at NULL. p1 at NULL, p0 at last node
                break;
        }
        return p0;
    }
    int getLinkedListLen(ListNode* head) // number of non-NULL nodes in list, or number of edges including last one pointing to NULL.
    {
        int len = 0; 
        ListNode* p = head;
        while(p)
        {
            len++;
            p = p->next;
        }
        return len;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Assume no cycles. Define the number of edges from headA to first common node as a. From headB to first common node as b.
        // The number of edges from first common node to NULL as c (same as number of common nodes).
        // We can find out a+c, b+c. Then reverse list A and traverse from headB. If reached headA, then there's intersection and we get a+b. From this c can be found, then a and b. If we start from headA and reach NULL before headA, then there's no intersection.
        // Visit entire list A, get count
        int lenA = getLinkedListLen(headA); // a+c
        int lenB = getLinkedListLen(headB); // b+c
        ListNode* lastNodep = reverseLinkedList(headA);
        int lenN = 0; // a + b
        ListNode* p = headB;
        while(p)
        {
            if(p == headA)
                break;
            lenN++;
            p = p->next;
        }
        if(!p) // p stopped at NULL, no intersection
            return NULL;
        assert(p == headA); // lenN is a + b.
        int c = (lenA+lenB-lenN)/2;
        int a = lenA - c;
        int b = lenB - c;
        // recover list A
        ListNode* recovered_headA = reverseLinkedList(lastNodep);
        assert(recovered_headA == headA);
        // Get first common node. Note that b could be zero.
        p = headB;
        int i = 0;
        while(p)
        {
            if(i == b)
                break;
            i++;
            p = p->next;
        }
        return p;
    }
};