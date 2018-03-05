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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        long long inf = 1LL << 40;
        return check(root->left, -inf, root->val) && check(root->right, root->val, inf);
    }

    bool check(TreeNode *x, long long lv, long long rv) {
        if (x == NULL) return true;
        return x->val < rv && x->val > lv && check(x->left, lv, x->val) && check(x->right, x->val, rv);
    }
};