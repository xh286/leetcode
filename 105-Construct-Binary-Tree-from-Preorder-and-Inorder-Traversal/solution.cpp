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
    int locateNode(int val, vector<int>& vec, int start, int end) // search val in vec[start...end], inclusive
    {
        int idx = -1;
        for(int i = start; i <= end; i++)
            if(vec[i] == val) idx = i;
        return idx;
    }
    TreeNode* buildTreeRecursive(vector<int>& preorder, vector<int>& inorder, int pre_start, int in_start, int len)
    {
        if(len <= 0) return NULL;
        int val = preorder[pre_start];
        int in_end = in_start+len-1;
        // find index of root in inorder
        int in_root = locateNode(val, inorder, in_start, in_end); 
        // must be successful, if not, it's an error
        if(in_root<0) return NULL;
        // Now inorder[in_start...in_root-1] is inorder sequence of left subtree
        TreeNode* p = new TreeNode(val);
        int len_left = in_root-in_start;
        p->left = buildTreeRecursive(preorder, inorder, pre_start+1, in_start, len_left);
        int len_right = in_end-in_root;
        p->right = buildTreeRecursive(preorder, inorder, pre_start+1+len_left, in_root+1, len_right);
        return p;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Assumption: no duplicate keys in tree?
        // Yes! Extreme case: all nodes same value, no way to reconstruct unique tree.
        return buildTreeRecursive(preorder, inorder, 0, 0, preorder.size());
    }
};