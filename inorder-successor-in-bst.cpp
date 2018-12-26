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
    bool fg = false;
    TreeNode *res;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        res = NULL;
        dfs(root, p);
        return res;
    }
    
    void dfs(TreeNode *x, TreeNode *y) {
        if (!x) return;
        dfs(x->left, y);
        if (fg) fg = false, res = x;
        if (x == y) fg = true;
        dfs(x->right, y);
    }
};