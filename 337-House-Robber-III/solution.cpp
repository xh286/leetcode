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
    int rob_withroot(TreeNode* p)
    {
        int result = p->val;
        if(p->left) result += rob_withoutroot(p->left);
        if(p->right) result += rob_withoutroot(p->right);
        return result;
    }
    int rob_withoutroot(TreeNode* p)
    {
        int result = 0;
        if(p->left) result += max(rob_withroot(p->left), rob_withoutroot(p->left));
        if(p->right) result += max(rob_withroot(p->right), rob_withoutroot(p->right));
        return result;
    }
    int rob(TreeNode* root) {
        // Optimal subtructure. For a subtree p with left & right, define f(p) as solution with p included, g(p) as solution without p included.
        // f(p) = p->val + g(left)+g(right). g(p) = max(f(left), g(left)) + max(f(right), g(right)).
        // For each node, we need to calculate f & g. How to store them? How to traverse the tree? Need post-order. Need bottom-up.
        // recursive solution is trivial and overlapping. This is DP.
        if(root) return max(rob_withroot(root), rob_withoutroot(root));
        else return 0;
    }
};