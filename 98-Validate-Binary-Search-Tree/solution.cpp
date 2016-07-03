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
    bool isValidBST(TreeNode* root) {
        // Now do iterative, using a stack
        stack<TreeNode*> trav_stack;
        TreeNode* subtree = root;
        long long running_max = (long long)INT_MIN - 1;
        while(true)
        {
            if(subtree)
            {
                trav_stack.push(subtree);
                // pre-order visit here
                subtree = subtree->left;
                continue;
            }
            if(trav_stack.empty()) return true;
            TreeNode * p = trav_stack.top();
            subtree = p->right;
            trav_stack.pop();
            // in-order visit here
            if(p->val <= running_max) return false;
            running_max = p->val;
        }
        
    }
};