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
    TreeNode *res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
    
    int dfs(TreeNode* x, TreeNode* p, TreeNode* q) {
        if (!x) return 0;
        int lt = dfs(x->left, p, q);
        int rt = dfs(x->right, p, q);
        int ans = 0;
        ans += lt + rt;
        if (lt == 1 && rt == 1) res = x;
        if (x == p || x == q ) {
            ans ++;
            if (ans == 2) res = x;
        }
        return ans;
    }
};