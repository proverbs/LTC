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
    TreeNode* convertBST(TreeNode* root) {
        cvt(root, 0);
        return root;
    }

    int cvt(TreeNode* x, int rtsm) {
        if (x == NULL) return 0;
        int res = 0;
        res += x->val;
        int rs = cvt(x->right, rtsm);
        int ls = cvt(x->left, x->val + rs + rtsm);
        x->val += rtsm + rs;
        res += rs + ls;
        return res;
    }
};