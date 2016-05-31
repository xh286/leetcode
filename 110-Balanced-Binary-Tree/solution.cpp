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
    int subtreeHeight(TreeNode* subtree) // return -1 if not balanced
    {
        if(subtree == NULL) return 0;
        int leftHeight, rightHeight;
        leftHeight = subtreeHeight(subtree->left);
        if(leftHeight < 0) return -1;
        rightHeight = subtreeHeight(subtree->right);
        if(rightHeight < 0) return -1;
        int heightDiff = leftHeight - rightHeight;
        if(heightDiff < 0) heightDiff *= -1;
        if(heightDiff > 1) return -1;
        height = max(leftHeight, rightHeight) + 1;
        return height;
    }
public:
    bool isBalanced(TreeNode* root) {
        subtreeHeight(root);
    }
};