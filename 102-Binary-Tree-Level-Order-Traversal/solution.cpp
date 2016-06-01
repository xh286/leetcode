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
    vector<vector<int>> r; // result
    void dfsLevelInsert(TreeNode* p, int level) // p is inserted at level, insert its subtrees
    {
        if(!p) return;
        // insert p->val
        if(r.size() < level) r.push_back(vector<int>()); // add new empty vector at end of r.
        r[level-1].push_back(p->val);
        // do left & right at increased level
        dfsLevelInsert(p->left, level+1);
        dfsLevelInsert(p->right, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // insert node in the right level. Either DFS / BFS always give left-right orders.
        // r.size() is the maximum level, and the level i is in r[i-1]. Level count starting from 1.
        // Already familiar with iterative solution, post-order DFS. Insert node into result when popping, using stack size before pop as level.
        // Try recursive solution here. Question is how to keep the level count right. Looks like we need to pass level as function parameter.
        dfsLevelInsert(root, 1);
        return r;
    }
};