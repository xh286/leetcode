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
    void dfs_pathSum(TreeNode* p, vector<vector<int>>& r, vector<int>& path, int sum)
    {
        if(!p) return;
        path.push_back(p->val);
        if(!p->left && !p->right) // leaf
        {
            if(p->val == sum)
                r.push_back(path);
            path.pop_back();
            return;
        }
        if(p->left) dfs_pathSum(p->left, r, path, sum-p->val);
        if(p->right) dfs_pathSum(p->right, r, path, sum-p->val);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r;
        vector<int> path;
        dfs_pathSum(root, r, path, sum);
        return r;
    }
};