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
    vector<int> inorderTraversal(TreeNode* root) {
        const TreeNode* p = root;
        vector<const TreeNode*> trav_stack;
        vector<int> output;
        while(true)
        {
            if(p)
            {
                trav_stack.push(p);
                
                p = p->left;
                continue;
            }
            if(trav_stack.empty())
            {
                break;
            }
            p = trav_stack.top();
            output.push_back(p->val);
            p = p->right;
            trav_stack.pop();
        }
        return output;
    }
};