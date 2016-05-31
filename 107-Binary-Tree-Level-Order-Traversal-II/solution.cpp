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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // BFS (right before left). Push result in a stack, then output stack.
        // Returned result is vector of vector! So it does not work.
        // How do we know the level has changed? When we process each node, add count by 2, if count crosses 2^n then new level.
        // Not complete, if any node is empty, count does not get incremented. Insert an empty node.
        // BFS uses more memory than DFS (n vs logn). So, prefer DFS.
        // This problem expects DFS based method. So DFS based method is optimal.
        // The vector<vector<int>> is designed to make it easier.
        // Do a post-order DFS. First time to find out maximum depth, second time to insert values into appropriate positions.
        // The visit functions are different, and the functions need to return a depth value. No, just copy-paste.
        
        // Note: Check at least 3 trivial cases here
        TreeNode* subtree = root;
        bool subtree_visited = false;
        vector<TreeNode*> trav_stack;
        int max_depth = 0;
        while(true)
        {
            if(subtree && !subtree_visited) // push nodes along left chains
            {
                trav_stack.push_back(subtree);
                subtree = subtree->left;
                continue;
            }
            if(trav_stack.empty()) break;
            TreeNode* parent = trav_stack.back();
            // subtree is left or right child of parent. If right, then done. If left, go to parent->right.
            if(subtree == parent->right)
            {
                if(subtree == parent->left) // leaf, update max depth here
                {
                    if(trav_stack.size() > max_depth)
                        max_depth = trav_stack.size();
                }
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
        // Here we have got the maximum depth of the tree. We only exit when trav_stack has become empty.
        subtree = root;
        subtree_visited = false;
        vector<vector<int>> r(max_depth, vector<int>()); // the number of levels is max_depth
        // Now we do DFS again and insert output at the right levels.
        while(true)
        {
            if(subtree && !subtree_visited) // push nodes along left chains
            {
                trav_stack.push_back(subtree);
                subtree = subtree->left;
                continue;
            }
            if(trav_stack.empty()) break;
            TreeNode* parent = trav_stack.back();
            // subtree is left or right child of parent. If right, then done. If left, go to parent->right.
            if(subtree == parent->right)
            {
                // push value of stack top into result
                int level = trav_stack.size();
                int val = parent->val;
                r[max_depth-level].push_back(val);
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
        return r;
    }
};