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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *prev = NULL, *cur = root;
        while (cur) {
            if (cur->val == key) break;
            else if (cur->val > key) prev = cur, cur = cur->left;
            else prev = cur, cur = cur->right;
        }
        if (cur) {
            if (cur->left && cur->right) {
                // find the max element in its left subtree
                TreeNode *x = cur->left;
                while (x->right) x = x->right;
                cur->val = x->val;
                cur->left = deleteNode(cur->left, x->val);
                return root;
            } else if (cur->right) {
                if (prev) {
                    if (prev->left == cur) prev->left = cur->right;
                    else prev->right = cur->right;
                    return root;
                } else {
                    return cur->right;
                }
            } else if (cur->left) {
                if (prev) {
                    if (prev->left == cur) prev->left = cur->left;
                    else prev->right = cur->left;
                    return root;
                } else {
                    return cur->left;
                }
            } else {
                if (prev) {
                    if (prev->left == cur) prev->left = NULL;
                    else prev->right = NULL;
                    return root;
                } else {
                    return NULL;
                }
            }
        } else {
            return root;
        }
    }
};