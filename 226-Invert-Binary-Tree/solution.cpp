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
    TreeNode* invertTree(TreeNode* root) {
        /* BFS. Switch left & right children. */
        std::queue<TreeNode *> bfs_queue;
        if(root)
            bfs_queue.push(root);
        while(!bfs_queue.empty())
        {
            TreeNode* parent = bfs_queue.front();
            bfs_queue.pop();
            TreeNode* temp_pointer = parent->left;
            parent->left = parent->right;
            parent->right = temp_pointer;
            if(parent->left)
            {
                bfs_queue.push(parent->left);
            }
            if(parent->right)
            {
                bfs_queue.push(parent->right);
            }
        }
        return root;
    }
};