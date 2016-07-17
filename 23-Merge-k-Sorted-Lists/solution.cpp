/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*
   Complexity: Assume k=2^m (e.g. m=3) length n lists, total 3 levels of merge, each merge k*n, so n*k*logk.
   Special case is mergesort, where k=n, n=1, so nlogn worst case. Good locality. Good.
   For this problem: keep a vector of pointers to lists. Each time find 2 shortest lists, then merge, and update length to sum and 0.
   Easier to use set, size equal to lists left. Need point to index in array, so map. Key is length, mapped value is index. Take smallest two, then merge into lower index.
 
 
 
 */

class Solution {
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(!list1 || !list2){ return (list1!=NULL)?list1:list2;}
        ListNode* host;
        ListNode* p;
        ListNode* q;
        if(list1->val <= list2->val)
        {
            host = list1, p = list1, q = list2;
        }
        else
        {
            host = list2, p = list2, q = list1;
        }
        // put sequence of nodes in q in between p & p->next. If no nodes in q satisfy, move p forward.
        ListNode* p_next = p->next;
        ListNode* new_q; // after putting nodes into p list, the next q to start with
        while(p_next && q) //Require p_next and q to work
        {
            // Maintain invariant: p->val <= q->val <= p_next->val
            while(p_next && p_next->val < q->val)
            {
                p = p_next;
                p_next = p->next;
            }
            if(!p_next) break;
            p->next = q;
            while(q->next && q->next->val<=p_next->val) q = q->next;
            new_q = q->next; // NULL or new_q->val > _next->val
            q->next = p_next;
            p = p_next;
            p_next = p->next;
            q = new_q;
        }
        p->next = q;
        return host;
    }
    int getListSize(ListNode* list)
    {
        int count = 0;
        while(list)
        {
            count++;
            list = list->next;
        }
        return count;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int,int> mp;
        int K = lists.size();
        for(int i=0; i<K; i++)
            mp.insert(pair<int,int>(getListSize(lists[i]),i));
        while(mp.size()>=2)
        {
            auto it = mp.begin();
            auto it2 = it+1;
            int new_size = it->first + it2->first;
            int idx1 = it->second;
            int idx2 = it2->second;
            int new_idx = min(idx1, idx2);
            lists[new_idx] = mergeTwoLists(lists[idx1], lists[idx2]);
            mp.erase(it);
            mp.erase(it2);
            mp.insert(pair<int,int>(new_size,new_idx));
        }
        return lists[0];
    }
};