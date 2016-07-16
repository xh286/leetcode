/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Using post-order traversal, then this becomes finding LCS (longest consecutive sequence) in a stack that frequently pushes & pops.
 // Define functions: push, pop, and get max_len.
 // A stack can contain multiple CS, like consecutive ranges with start & length.
 // Maintain length of last segment. At least 1. 
 // So, keep max_len, cur_len.
class Solution {
private:
    void longestSeg(TreeNode* p, int parent_val, int& max_len, int cur_len)
    {
        if(!p) return;
        if(p->val == parent_val+1)
        {
            cur_len++;
            max_len = max(max_len, cur_len);
        }
        else
        {
            cur_len = 1;
        }
        longestSeg(p->left, p->val, max_len, cur_len);
        longestSeg(p->right, p->val, max_len, cur_len);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int max_len = 1;
        int cur_len = 1;
        longestSeg(root->left, root->val, max_len, cur_len);
        longestSeg(root->right, root->val, max_len, cur_len);
        return max_len;
    }
};