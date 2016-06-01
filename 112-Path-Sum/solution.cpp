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
    bool hasPathSum(TreeNode* root, int sum) {
        // Iterative solution is better in that it can break the loop immediately, no need to unwind through the stack.
        // Do an iterative post-order DFS. Keep track of sum of nodes in stack. And compare to the given sum at leaf nodes.
        //if(!root && sum==0) return true;
        vector<TreeNode*> trav_stack; // uses push_back(x), pop_back(), back() and size(), empty().
        TreeNode* subtree = root; // subtree root pointer
        bool subtree_visited = false;
        int stack_sum = 0;
        while(true) // terminate when sum is found, or stack becomes empty
        {
            if(subtree && !subtree_visited) // post-order DFS needs protection with boolean to avoid infinite loop.
            {
                trav_stack.push_back(subtree); // push all nodes here, along left-chains.
                stack_sum += subtree->val;
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
                    //parent is leaf, compare stack_sum with sum
                    if(stack_sum == sum)
                        return true;
                }
                // pop parent
                trav_stack.pop_back();
                subtree = parent;
                subtree_visited = true;
                stack_sum -= subtree->val;
            }
            else
            {
                subtree = parent->right;
                subtree_visited = false;
            }
        }
        return false;
    }
};