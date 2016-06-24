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
    void rlDFS(TreeNode* root, vector<int>& r, vector<int>& v, int level)
    {
        if(!root) return;
        if(level > v.size())
        {
            v.push_back(true);
            r.push_back(root->val);
        }
        else
        {
            if(v[level-1] == false)
            {
                r[level-1] = root->val;
                v[level-1] = true;
            }
        }
        rlDFS(root->right, r, v, level+1);
        rlDFS(root->left, r, v, level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // Do a right-to-left DFS, and remember whether each level already output something.
        vector<int> r;
        vector<bool> v;
        rlDFS(root, r, v, 1);
        return r;
    }
};