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
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        if (!root) return res;
        dfs(root, to_string(root->val));
        return res;
    }
    
    void dfs(TreeNode* x, string s) {
        if (!x->left && !x->right) {
            res.push_back(s);
            return;
        }
        if (x->left) {
            dfs(x->left, s + "->" + to_string(x->left->val));
        } 
        if (x->right) {
            dfs(x->right, s + "->" + to_string(x->right->val));
        }
    }
};