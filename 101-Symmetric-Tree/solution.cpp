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
    bool twoTreesSymmetric(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if( (!p && q) || (p && !q) ) return false;
        return((p->val == q->val) && twoTreesSymmetric(p->left, q->right) && twoTreesSymmetric(p->right, q->left));
    }
    bool isSymmetric(TreeNode* root) {
        // First recursive solution. Good reference for iterative solution too.
        if(root == NULL) return true;
        return(twoTreesSymmetric(root->left, root->right));
    }
    // Iterative solution can be inspired from recursive version. Do simultaneous pre-order DFS (regular & reverse order).
    // Do the pointer comparisons like above, and value comparisons when pushing into stacks.
};