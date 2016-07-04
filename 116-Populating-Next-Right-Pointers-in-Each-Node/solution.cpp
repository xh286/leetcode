/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // For each node, do 3 things:
        // 1. if left & right exist, p = left, q = right, p->next = q.
        // 2. while(p->right && q->left){p = p->right, q = q->left, p->next = q;}
        // 3. If children exist, call this for children nodes.
        if(!root) return;
        if(root->left && root->right)
        {
            TreeLinkNode* p = root->left;
            TreeLinkNode* p = root->right;
            p->next = q;
            while(p->right && q->left)
            {
                p = p->right, q = q->left;
                p->next = q;
            }
            connect(root->left);
            connect(root->right);
        }
    }
};