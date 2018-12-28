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
    int res;
    int countUnivalSubtrees(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
    
    bool dfs(TreeNode *x) { // return whether it is a uni-subtree
        if (x == NULL) return true;
        bool fg = true;
        if (x->left) fg &= dfs(x->left);
        if (x->right) fg &= dfs(x->right);
        if (x->left) fg &= x->left->val == x->val;
        if (x->right) fg &= x->val == x->right->val;
        res += fg;
        return fg;
    }
};