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
    vector<int> preorderTraversal(TreeNode* root) {
        const TreeNode* p = root; // promise to not change the tree, uses a stack.
        stack<const TreeNode*> t_stack;
        vector<int> output;
        while(true) // traverse tree along 45 degree left-chains. First the left-most chain, then next, ...
        {
            if(p)
            {
                t_stack.push(p);
                output.push_back(p->val);//print before moving down, pre-order
                p = p->left;
                continue;
            }
            // empty left found. If stack also empty, then we are at right-most left. erminate.
            if(t_stack.empty())
                break;
            // move on to right branch, and pop parent. Print here if in-order.
            p = t_stack.top()->right;
            t_stack.pop();
        }
        return output;
    }
};