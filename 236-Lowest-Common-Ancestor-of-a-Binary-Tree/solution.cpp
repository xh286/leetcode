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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        vector<vector<TreeNode*>> res(2,vector<TreeNode*>());
        int idx = 0;
        vector<TreeNode*> trav_stack;
        TreeNode* subtree = root;
        bool subtree_popped = false;
        while(true) // post-order traversal
        {
            if(subtree && !subtree_popped) // if popped from stack, no need to process its children further
            {
                trav_stack.push_back(subtree);
                if(subtree == p || subtree == q)
                    res[idx++] == trav_stack;
                if(idx==2) break;
                subtree = subtree->left;
                continue;
            }
            if(trav_stack.size()==0) break; // exit after all nodes visited
            TreeNode* parent = trav_stack.back();
            // subtree is always child of stack top.
            if(subtree == parent->right) // subtree NULL, or subtree already popped
            {
                // if parent->right = parent->left = NULL, also here
                trav_stack.pop_back();
                subtree = parent;
                subtree_popped = true;
            }
            else
            {
                subtree = parent->right;
                subtree_popped = false;
            }
        }
        // path from root to p & q in res. Find last common node
        int max_len = min(res[0].size(), res[1].size());
        int i=1;
        for(; i<max_len; i++) // first entries are root
            if(res[0][i] != res[1][i]) break;
        return res[0][i-1];
    }
};