/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Two steps: tree -> vector, then vector -> string. Here we use comma separated string. Integer values and *.
        // Problem: what to put into vector if NULL? So, just insert *, directly. When decoding, pass ref to integer, and use boolean to identify whether it's NULL. If NULL, don't use the integer value.
        // Encode into complete trees as OJ does, plus trailing nulls. So length is always 2^n-1, n is # of levels.
        // If node->child is NULL, push in NULL. When popping, if NULL, push in 2 NULLs.
        // How to finish? Count the # of non-NULLs pushed at current level, if zero, then stop.
        // Storing pre-order and in-order sequence doesn't work if tree contains duplicate values.
        // Level order encoding into 2^n-1 comma separated integers/*s.
        // Not efficient. Store val & left_right_mask (0b11 means both left & right).
        // Use ostringstream for output.
        if(!root) return string();
        ostringstream s; // return its .str() member.
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            //visit p here
            int left_right_mask = 0;
            if(p->left)
            {
                q.push(p->left);
                left_right_mask |= 1<<1;
            }
            if(p->right)
            {
                q.push(p->right);
                left_right_mask |= 1<<0;
            }
            s << " " << p->val << " " << left_right_mask; // space separated, easier to extract
        }
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        int val;
        int left_right_mask;
        TreeNode* root = NULL;
        bool first_node = true;
        queue<TreeNode**> q;
        while(s) // in each loop, read in one pair of val+mask, and set previous pointer to this one.
        {
            s >> val;
            s >> left_right_mask;
            TreeNode* p = new TreeNode(val);
            
            if(left_right_mask & (1<<1)) q.push(&(p->left));
            if(left_right_mask & (1<<0)) q.push(&(p->right));
            
            if(first_node) {root = p; first_node = false;}
            else{TreeNode** qq = q.front(); q.pop(); *qq = p;}
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));