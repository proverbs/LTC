/*dfs*/
/*typical*/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        int rt = preorder[0];
        TreeNode* res = NULL;
        dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, res);
        return res;
    }

    void dfs(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir, TreeNode* &x) {
        if (pr < pl) x = NULL;
        else {
            int rt = preorder[pl];
            x = new TreeNode(rt);
            for (int i = il; i <= ir; i ++) {
                if (inorder[i] == rt) {
                    dfs(preorder, pl + 1, pl + i - il, inorder, il, i - 1, x->left);
                    dfs(preorder, pl + i - il + 1, pr, inorder, i + 1, ir, x->right);
                    break;
                }
            }
        }
    }
};