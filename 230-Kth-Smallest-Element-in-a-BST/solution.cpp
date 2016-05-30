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
    int kthSmallest(TreeNode* root, int k) {
        // In-order DFS, and output kth element. No need to complete full traversal, so don't use Morris.
        TreeNode* p = root;
        stack<TreeNode*> trav_stack;
        int c = 0;
        while(true)
        {
            if(p)
            {
                trav_stack.push(p);
                p = p->left;
                continue;
            }
            if(trav_stack.empty()) break; // actually no need here since k is always valid
            // move to parent of NULL left pointer
            p = trav_stack.top(); // run the "output function" here for in-order traversal.
            c++;
            if(c == k) return p->val;
            trav_stack.pop();
            p = p->right;
        }
        
        
        // For follow up question, a parent pointer will be most convenient. 
        // If removed key < kth, then iterator--, or go to "pre". Otherwise, iterator++ (assuming unique keys), or go to "next".
        // Parent pointer easy to update when modifying tree.
        // If cannot modify tree itself, then maintain a post-order-traversal stack, or two pre-order traversal stacks.
        // In practice, also need to consider cost of self-balancing.
    }
};