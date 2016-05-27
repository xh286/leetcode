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
    void deleteNode(ListNode* node) {
        assert(node->next != NULL);
        node->val = node->next->val;
        //ListNote* p= node->next;
        node->next = node->next->next;
        //free(p);
    }
};