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
    int processNode(TreeNode* p, vector<vector<int>>& r)
    {
        // return dist2leaf. For null p, do nothing, return -1.
        // For non-null, dist2leaf = max(processNode(p->left, r), processNode(p->right, r))+1.
        // insert into r[dist2leaf], then return dist2leaf.
        if(!p) return -1;
        int dist2leaf = max(processNode(p->left, r), processNode(p->right, r)) + 1;
        while(dist2leaf>=r.size()) r.push_back(vector<int>());
        r[dist2leaf].push_back(p->val);
        return dist2leaf;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> r;
        processNode(root, r);
        return r;
    }
};