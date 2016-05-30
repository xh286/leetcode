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
    int rob(TreeNode* root) {
        // Optimal subtructure. For a subtree p with left & right, define f(p) as solution with p included, g(p) as solution without p included.
        // f(p) = p->val + g(left)+g(right). g(p) = max(f(left), g(left)) + max(f(right), g(right)).
        // For each node, we need to calculate f & g. How to store them? How to traverse the tree? Need post-order. Need bottom-up.
        // recursive solution is trivial and overlapping. This is DP.
        if(root == NULL) return 0;
        // Post order DFS. Update parent value when returning from left subtree and right subtree.
        stack<TreeNode* > trav_stack;
        stack<int> f_stack;
        stack<int> g_stack;
        bool subtree_visited = false;
        TreeNode* subtree = root;
        int f, g;
        while(true)
        {
            if(subtree && !subtree_visited) // p_visited protection necessary for post-order DFS. Set to true when pop p from stack.
            {
                trav_stack.push(subtree); // push left chains by pre-order
                f_stack.push(subtree->val);
                g_stack.push(0);
                subtree = subtree->left;
                continue;
            }
            // Subtree is either NULL or visited. Go back to stack top.
            if(trav_stack.empty()) break;
            TreeNode* parent = trav_stack.top();
            // subtree is always left or right child of stack top. If right child, then done.
            if(subtree == parent->right)
            {
                if(subtree == parent->left) // parent is leaf
                {
                }
                trav_stack.pop(); // pop parent, process here
                f = f_stack.top();
                g = g_stack.top();
                f_stack.pop();
                g_stack.pop();
                if(f_stack.empty()) break;
                f_stack.top() += g;
                g_stack.top() += max(f, g);
                subtree = parent; // go up one level
                subtree_visited = true;
            }
            else // left child is done
            {
                subtree = trav_stack.top()->right;
                subtree_visited = false;
            }
        }
        return max(f,g);
    }
};