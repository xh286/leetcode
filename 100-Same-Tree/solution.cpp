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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> p_stack; // stack for DFS
        std::stack<TreeNode*> q_stack; // stack for DFS
        TreeNode* p_subtree = p;
        TreeNode* q_subtree = q;
        while(true)
        {
            if((p_subtree && !q_subtree) || (!p_subtree && q_subtree)) // the two trees are different
                return false;
            if(p_subtree) // push along left chains
            {
                assert(q_subtree);
                p_stack.push(p_subtree);
                q_stack.push(q_subtree);
                if(p_subtree->val != q_subtree->val)
                    return false;
                p_subtree = p_subtree->left;
                q_subtree = q_subtree->left;
                continue;
            }
            if(p_stack.empty() || q_stack.empty()) // terminate condition
                break;
            // Here we got NULL pointer while going down along the left chains
            assert(!q_subtree);
            p_subtree = p_stack.top()->right;
            q_subtree = q_stack.top()->right;
            p_stack.pop();
            q_stack.pop();
        }
        if(!p_stack.empty() || !q_stack.empty())
            return false;
        // If arrived here, the two trees are identical.
        return true;
    }
};