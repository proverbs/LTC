/*树形DP*/

#include <map>

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
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
        map<TreeNode*, int> dp, f;
        dp[NULL] = f[NULL] = 0;
        dfs(root, dp, f);
        return max(dp[root], f[root]);
    }

    void dfs(TreeNode* x, map<TreeNode*, int>& dp, map<TreeNode*, int>& f) {
        if (x == NULL) return;
        dfs(x->left, dp, f);
        dfs(x->right, dp, f);
        dp[x] = x->val + f[x->left] + f[x->right];
        f[x] = max(dp[x->left], f[x->left]) + max(dp[x->right], f[x->right]);
    }
};