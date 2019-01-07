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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        vector<int> lb, rb;
        get_left_bottom(root->left, true, lb);
        get_right_bottom(root->right, true, rb);
        for (int a : lb) res.push_back(a);
        while (rb.size()) res.push_back(rb.back()), rb.pop_back();
        return res;
    }
    
    void get_left_bottom(TreeNode* x, bool fg, vector<int>& bd) {
        if (!x) return;
        if (fg) bd.push_back(x->val);
        if (x->left) {
            get_left_bottom(x->left, fg, bd);
            get_left_bottom(x->right, false, bd);
        } else if (x->right) {
            get_left_bottom(x->right, fg, bd);
        } else {
            if (!fg) bd.push_back(x->val);
        }
    }
    
    void get_right_bottom(TreeNode* x, bool fg, vector<int>& bd) {
        if (!x) return;
        if (fg) bd.push_back(x->val);
        if (x->right) {
            get_right_bottom(x->right, fg, bd);
            get_right_bottom(x->left, false, bd);
        } else if (x->left) {
            get_right_bottom(x->left, fg, bd);
        } else {
            if (!fg) bd.push_back(x->val);
        }
    }
};