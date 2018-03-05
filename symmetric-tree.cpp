/*dfs*/

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return cmp(root->left, root->right);
    }

    bool cmp(TreeNode *x, TreeNode *y) {
        if (x != NULL && y != NULL) {
            return x->val == y->val && cmp(x->left, y->right) && cmp(x->right, y->left);
        } 
        return x == NULL && y == NULL;
    }
};