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
    long long running_max;
    bool subisValidBST(TreeNode* p)
    {
        if(!p) return true;
        if(!subisValidBST(p->left)) return false;
        if(running_max >= p->val) return false; // must be <
        running_max = p->val; 
        if(!subisValidBST(p->right)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        // Try recursive solution!
        // Note that this BST assumes unique keys. This is usually definition.
        // Idea is in-order traversal, and track running maximum, any new node needs to be greater than the maximum.
        // Could use a private data member to achieve this.
        running_max = (long long)INT_MIN - 1;
        return subisValidBST(root);
    }
};