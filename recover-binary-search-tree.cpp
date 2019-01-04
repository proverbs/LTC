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
    TreeNode *sm, *lg;
    TreeNode* last;
    void recoverTree(TreeNode* root) {
        last = NULL;
        sm = lg = NULL;
        dfs_sm(root);
        last = NULL;
        dfs_lg(root);
        cout << sm->val << lg->val << endl;
        swap(sm->val, lg->val);
    }
    
    void dfs_sm(TreeNode* x) {
        if (!x) return;
        dfs_sm(x->left);
        if (last && last->val > x->val) sm = x;
        last = x;
        dfs_sm(x->right);
    }
    
    void dfs_lg(TreeNode* x) {
        if (!x) return;
        dfs_lg(x->right);
        if (last && last->val < x->val) lg = x;
        last = x;
        dfs_lg(x->left);
    }
};