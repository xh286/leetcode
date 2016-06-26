/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        unordered_map<RandomListNode*, int> a2j;
        RandomListNode* p;
        int k;
        a2j[(RandomListNode*) nullptr] = 0;
        for(p = head, k = 0; p != NULL; p = p->next)
        {
            a2j[p] = ++k;
        }
        int len = k;
        vector<int> i2j(len+1,0);
        for(p = head, k = 0; p!= NULL; p= p->next)
        {
            i2j[++k] = a2j[p->random];
        }
        vector<RandomListNode*> j2a(len+1,(RandomListNode*) nullptr);
        RandomListNode* new_head = new RandomListNode(head->label);
        RandomListNode* p2 = new_head;
        j2a[1] = new_head;
        for(p = head->next, k = 1; p!= NULL; p= p->next)
        {
            p2->next = new RandomListNode(p->label);
            p2 = p2->next;
            j2a[++k] = p2;
        }
        for(p=new_head, k=0; p != NULL, p=p->next)
        {
            p->random = j2a[i2j[++k]];
        }
        return new_head;
    }
};