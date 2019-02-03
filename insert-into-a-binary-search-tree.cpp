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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insert(root, val);
        return root;
    }
    
    void insert(TreeNode*& x, int val) { // reference to pointer
        if (!x) x = new TreeNode(val);
        else {
            if (x->val > val) insert(x->left, val);
            else insert(x->right, val);
        }
    }
};