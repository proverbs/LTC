/*dfs*/
/*tipical, 可以写的非常简单*/

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
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int dfs(TreeNode* x, int sy) {
        if (x == NULL) return 0;
        return (x->val == sy) + dfs(x->left, sy - x->val) + dfs(x->right, sy - x->val);
    }
};