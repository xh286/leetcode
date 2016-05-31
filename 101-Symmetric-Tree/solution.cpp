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
    bool isSymmetric(TreeNode* root) {
        // First recursive solution. Good reference for iterative solution too.
        if(root == NULL) return true;
        if(root->left && !root->right) return false;
        if(!root->left && root->right) return false;
        bool left_right_equal = (root->left->val == root->right->val);
        return ( left_right_equal && isSymmetric(root->left) && isSymmetric(root->right) );
    }
};