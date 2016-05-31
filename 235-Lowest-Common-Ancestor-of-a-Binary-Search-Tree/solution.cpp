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
private:
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Naive solution: Do Post-order DFS for p, save path from root to p; repeat for q; then compare the two paths.
        // Problem is C++ stack does not allow iterating over all nodes in stack. So we use vectors instead.
        // An improvement is as soon as one of p and q is found, copy the current stack to another vector, then continue until the other is found.
        vector<TreeNode*> trav_stack;
        TreeNode* subtree = root;
        vector<TreeNode*> first_path;
        bool found_one = false;
        bool subtree_visited = false;
        while(true)
        {
            if(subtree && !subtree_visited)
            {
                trav_stack.push_back(subtree); // all the nodes are pushed here
                if(subtree == p || subtree == q) // found an element
                {
                    if(found_one) break; // second node also found, stop
                    first_path = trav_stack; // contains path from root to first found element
                    found_one = true;
                }
                subtree = subtree->left;
                continue;
            }
            if(trav_stack.empty()) break; // actually should be error condition in this case
            TreeNode* parent = trav_stack.back();
            // subtree is either right (then parent is done, move up) or left (then move to parent->right) child of parent
            if(subtree == parent->right)
            {
                //if(subtree == parent->left){} // leaf
                trav_stack.pop_back(); // visit node here for post-order DFS
                subtree = parent;
                subtree_visited = true; // set marker so that in next iteration we don't push its left subtree into stack again
            }
            else // non-null left subtree
            {
                subtree = parent->right;
                subtree_visited = false; // set marker as parent is not visited yet
            }
        }
        // now trav_stack and first_path contain paths from root to p and q. Find last common entry.
        TreeNode* result = NULL;
        if(first_path.empty() || trav_stack.empty()) return NULL; // at least one not found, need study more here.
        // first entry must be root, no need to test
        int i, j;
        for(i=1, j=1; i<first_path.size() && j < trav_stack.size() ; i++, j++)
        {
            if(first_path[i] != trav_stack[j])
            {
                break;
            }
        }
        // when we reached here, it could be due to unequal, or one vector runs out.
        // No, the paths must include p & q as last entries, so they must be unequal before running out, unless p==q.
        return first_path[i-1];
    }
};