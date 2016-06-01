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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        vector<TreeNode*> trav_stack; // uses push_back(x), pop_back(), back() and size(), empty().
        TreeNode* subtree = root; // subtree root pointer
        bool subtree_visited = false;
        int min_depth = INT_MAX;
        while(true) // terminate when stack becomes empty
        {
            if(subtree && !subtree_visited) // post-order DFS needs protection with boolean to avoid infinite loop.
            {
                trav_stack.push_back(subtree); // push all nodes here, along left-chains.
                subtree = subtree->left;
                continue;
            }
            if(trav_stack.empty()) break; // return false
            TreeNode* parent = trav_stack.back();
            // subtree is either right or left child of parent, or both (leaf, left==right==NULL). If right, done. If left, continue with right.
            if(subtree == parent->right)
            {
                if(subtree == parent->left)
                {
                    //parent is leaf, compare
                    if(trav_stack.size() < min_depth)
                        min_depth = trav_stack.size();
                }
                // pop parent
                trav_stack.pop_back();
                subtree = parent;
                subtree_visited = true;
            }
            else
            {
                subtree = parent->right;
                subtree_visited = false;
            }
        }
        return min_depth;
    }
};