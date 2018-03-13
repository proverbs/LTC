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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return root;
        if (root == p || root == q) return root;
        TreeNode* n1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* n2 = lowestCommonAncestor(root->right, p, q);
        if (n1 != NULL && n2 != NULL) return root;
        return n1 == NULL ? n2 : n1;
    }
};