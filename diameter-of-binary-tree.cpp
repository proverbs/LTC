/*如果不是二叉树需要用dp*/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

    int dfs(TreeNode* x, int& res) {
        if (x == NULL) return -1;
        int lt = dfs(x->left, res);
        int rt = dfs(x->right, res);
        res = max(res, lt + rt + 2);
        return max(lt, rt) + 1;
    }
};