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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1;
        if (!root->left) return -1;
        if (root->left->val == root->right->val) {
            return mymin(findSecondMinimumValue(root->left), findSecondMinimumValue(root->right));
        } else if (root->left->val < root->right->val) {
            return mymin(findSecondMinimumValue(root->left), root->right->val);
        } else {
            return mymin(root->left->val, findSecondMinimumValue(root->right));
        }
    }

    int mymin(int x, int y) {
        if (x == -1) return y;
        if (y == -1) return x;
        return min(x, y);
    }
};