/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    bool isleaf(TreeLinkNode *p) // p not NULL
    {
        return (!p->left && !p->right);
    }
    TreeLinkNode* findRightmostAtLevel(TreeLinkNode *p, int level) // return NULL if not found. level>=0
    {
        if(!p) return NULL; // level 0? root is considered level 0
        if(p && (level==0)) return p;
        if(level>0)
        {
            TreeLinkNode* p_from_right = findRightmostAtLevel(p->right, level-1);
            if(p_from_right) return p_from_right;
            return findRightmostAtLevel(p->left, level-1);
        }
    }
    TreeLinkNode* findLeftmostAtLevel(TreeLinkNode *p, int level) // return NULL if not found. level>=0
    {
        if(!p) return NULL; // level 0? root is considered level 0
        if(p && (level==0)) return p;
        if(level>0)
        {
            TreeLinkNode* p_from_left = findLeftmostAtLevel(p->left, level-1);
            if(p_from_left) return p_from_left;
            return findLeftmostAtLevel(p->right, level-1);
        }
    }
public:
    void connect(TreeLinkNode *root) {
        // For each node, do 3 things:
        // 1. if left & right exist, p = left, q = right, p->next = q.
        // 2. while(p->right && q->left){p = p->right, q = q->left, p->next = q;}
        // 3. If children exist, call this for children nodes.
        if(!root) return;
        if(root->left && root->right)
        {
            int level = 0;
            while(true) // at each level, find rightmost of left and leftmost of right, point to.
            {
                TreeLinkNode* p = findRightmostAtLevel(root->left, level);
                TreeLinkNode* q = findLeftmostAtLevel(root->right, level);
                if(p && q) {p->next = q; level++;}
                else break;
            }
        }
        if(root->left) connect(root->left);
        if(root->right) connect(root->right);
    }
};