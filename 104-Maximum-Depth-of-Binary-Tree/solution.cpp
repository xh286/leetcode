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
        bool subtree_popped = false; // with post-order DFS, when going up, we need to make sure the left & right children of a popped node does not get traversed again.
        int max_depth = 0;
        while(true)
        {
            if(subtree && !subtree_popped) // subtree to traverse is not empty, and not popped, push into stack.
            {
                dfs_stack.push_back(subtree);
                if(dfs_stack.size()>max_depth)
                {
                    max_depth = dfs_stack.size();
                }
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
            if(subtree == dfs_stack.back()->left && subtree != dfs_stack.back()->right) // returning from left subtree, and stack top is not leaf. Otherwise infinite loop.
            {
                subtree = dfs_stack.back()->right;
                subtree_popped = false;
            }
            else // returning from right subtree, pop parent.
            {
                subtree = dfs_stack.back();
                subtree_popped = true;
                dfs_stack.pop_back();
            }
        }
        return max_depth;
    }
};