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
        dq.push_back(root);
        int popped = 0;
        int level = 0;
        //int push_count = 0; don't need to count
        int dir = 1;
        while(true)
        {
            int to_pop = dq.size();
            if(to_pop>0) r.push_back(vector<int>());
            else break;
            for(int popped = 0; popped < to_pop; popped++)
            {
                TreeNode* p;
                if(dir == 1)
                {
                    p = dq.front();
                    dq.pop_front();
                    if(p->left) dq.push_back(p->left);
                    if(p->right) dq.push_back(p->right);
                }
                else
                {
                    p = dq.back();
                    dq.pop_back();
                    if(p->right) dq.push_front(p->right);
                    if(p->left) dq.push_front(p->left);
                }
                r[level].push_back(p->val);
            }
            // One level done
            level++;
            dir *= -1;
        }
        return r;
    }
};