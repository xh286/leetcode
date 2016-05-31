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
    bool hasCycle(ListNode *head) {
        // a hash set of the pointers would be sufficient, but not constant space.
        // The problem is like finding duplicates in an array.
        // The nodes are divided into two parts: not in cycle, in cycle. We don't know how long the cycle is.
        // Key question is the end condition.
        // The solution is fast/slow runner. The fast will keep waiting for the slow. Every time the fast increments, compare with the slow.
        if(!head) return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        unsigned counter = 0;
        while(fast) // if returned from while loop, then cycle found
        {
            if(fast == slow) return true;
            fast = fast->next;
            if(counter & 1) slow = slow->next;
            counter++;
        }
        return false;
    }
};