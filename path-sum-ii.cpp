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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        if (!root) return res;
        vector<int> t({root->val});
        dfs(root, sum, root->val, t);
        return res;
    }
    
    void dfs(TreeNode* x, int sum, int cur, vector<int>& r) {
        if (!x->left && !x->right) {
            if (sum == cur) res.push_back(r);
            return;
        }
        
        if (x->left) {
            r.push_back(x->left->val);
            dfs(x->left, sum, cur + x->left->val, r);
            r.pop_back();
        }
        if (x->right) {
            r.push_back(x->right->val);
            dfs(x->right, sum, cur + x->right->val, r);
            r.pop_back();
        }
    }
};