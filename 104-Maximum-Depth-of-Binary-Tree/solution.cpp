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
    int maxDepth(TreeNode* root) {
        /* post-order DFS, stack keeps the path from root to current node. Return maximum length of stack. */
        std::vector<TreeNode *> dfs_stack;
        TreeNode * subtree = root;
        bool subtree_popped = false; // with post-order DFS, parents are only popped after both left/right are traversed. We need to make sure the left & right children of a popped node does not get traversed again.
        int max_depth = 0;
        while(true)
        {
            if(subtree && !subtree_popped) // subtree to traverse is not empty, and not popped, push into stack.
            {
                dfs_stack.push_back(subtree);

                subtree = subtree->left;
                subtree_popped = false;
                continue;
            }
            // Node is only popped after both left & right subtrees are visited. If stack is empty, terminate.
            if(dfs_stack.empty())
            {
                break;
            }
            // subtree is now child of stack top. Are we returning from left subtree, or right subtree? 
            TreeNode * subtree_parent = dfs_stack.back();
            // Is stack top leaf?
            if(subtree_parent->left == NULL && subtree_parent->right == NULL)
            {
                if(dfs_stack.size()>max_depth)
                {
                    max_depth = dfs_stack.size();
                }
                subtree = subtree_parent;
                dfs_stack.pop_back();
                subtree_popped = true;
                continue;
            }
            // returning from left/right subtree of non-leaf node
            if(subtree == subtree_parent->left) // returning from left subtree.
            {
                subtree = subtree_parent->right;
                subtree_popped = false;
            }
            else // returning from right subtree, pop parent.
            {
                subtree = subtree_parent;
                subtree_popped = true;
                dfs_stack.pop_back();
            }
        }
        return max_depth;
    }
};