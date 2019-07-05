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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return root;
        if (root->left) {
            TreeNode *rt = root->right;
            TreeNode *lt = root->left;
            root->left = root->right = NULL;
            TreeNode *t = upsideDownBinaryTree(lt);
            lt->left = rt;
            lt->right = root;
            return t;
        } else return root;
    }
};