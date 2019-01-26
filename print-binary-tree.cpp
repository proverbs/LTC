// divide and conquer

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
    vector<vector<string>> printTree(TreeNode* root) {
        int ht = get_height(root);
        vector<vector<string>> res(ht, vector<string>((1 << ht) - 1));
        
        fill(root, res, 0, (1 << ht) - 2, 0);
        return res;
    }
    
    int get_height(TreeNode* root) {
        if (!root) return 0;
        int ht = 1;
        if (root->left) ht = max(ht, get_height(root->left) + 1);
        if (root->right) ht = max(ht, get_height(root->right) + 1);
        return ht;
    }
    
    void fill(TreeNode* root, vector<vector<string>>& res, int lt, int rt, int ht) {
        int mid = lt + rt >> 1;
        res[ht][mid] = to_string(root->val);
        if (root->left) fill(root->left, res, lt, mid - 1, ht + 1);
        if (root->right) fill(root->right, res, mid + 1, rt, ht + 1);
    }
};