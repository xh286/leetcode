/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // BFS using a queue. Remember number of nodes at current level. Pop this many times before increase level.
        vector<vector<int>> r;
        deque<TreeNode*> dq;
        if(!root) return r;
        int to_pop;
        dq.push_back(root);
        to_pop = 1;
        int popped = 0;
        int level = 0;
        int push_count = 0;
        int dir = 1;
        while(true)
        {
            if(to_pop>0) r.push_back(vector<int>());
            else break;
            for(int popped = 0; popped < to_pop; popped++)
            {
                if(dir == 1)
                {
                TreeNode* p = dq.front();
                dq.pop_front();
                r[level].push_back(p->val);
                if(p->left)
                {
                    dq.push_back(p->left);
                    push_count++;
                }
                if(p->right)
                {
                    dq.push_back(p->right);
                    push_count++;
                }
                }
                else
                {
                TreeNode* p = dq.back();
                dq.pop_back();
                r[level].push_back(p->val);
                if(p->right)
                {
                    dq.push_front(p->right);
                    push_count++;
                }
                if(p->left)
                {
                    dq.push_front(p->left);
                    push_count++;
                }
                }
            }
            // One level done
            to_pop = push_count;
            push_count = 0;
            level++;
            dir *= -1;
        }
        return r;
    }
};