
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return dfs(root, 1);
    }

    int dfs(TreeNode* x, int depth) {
        int rt = depth;
        if (x->left != NULL) rt = max(rt, dfs(x->left, depth + 1));
        if (x->right != NULL) rt = max(rt, dfs(x->right, depth + 1));
        return rt; 
    }
};