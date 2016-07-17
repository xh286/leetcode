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
    void getMinLRDiff(TreeNode* p, int& max_diff, int& min_diff, int diff, bool isleft) // diff zero at root. LR true if left, false if right.
    {
        if(!p) return;
        if(isleft)
        {
            diff = diff-1;
            min_diff = min(min_diff,diff);
        }
        else
        {
            diff = diff+1;
            max_diff = max(max_diff,diff);
        }
        getMinLRDiff(p->left, max_diff, min_diff, diff, true);
        getMinLRDiff(p->right, max_diff, min_diff, diff, false);
    }
    
    void insertVertical(TreeNode* p, int diff, vector<vector<int>>& ret, int offset) // insert into ret[diff+offset].
    {
        if(!p) return;
        ret[diff+offset].push_back(p->val);
        insertVertical(p->left, diff-1, ret, offset);
        insertVertical(p->right, diff+1, ret, offset);
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        int min_diff = 0;
        int max_diff = 0;
        getMinLRDiff(root->left, max_diff, min_diff, 0, true);
        getMinLRDiff(root->right, max_diff, min_diff, 0, false);
        // Now insert values into ret with offset.
        ret.resize(max_diff-min_diff+1);
        insertVertical(root, 0, ret, -min_diff);
    }
};