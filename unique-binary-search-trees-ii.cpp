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
    vector<TreeNode*> generateTrees(int n) {
        if (!n) return vector<TreeNode*>();
        return dfs(1, n);
    }
    
    vector<TreeNode*> dfs(int lt, int rt) {
        vector<TreeNode*> res;
        if (rt < lt) {
            res.push_back(NULL);
            return res;
        }
        for (int i = lt; i <= rt; i ++) {
            vector<TreeNode*> vlt = dfs(lt, i - 1);
            vector<TreeNode*> vrt = dfs(i + 1, rt);
            for (TreeNode* ilt : vlt)
                for (TreeNode* irt : vrt) {
                    TreeNode *x = new TreeNode(i);
                    x->left = ilt;
                    x->right = irt;
                    res.push_back(x);
                }
        }
        return res;
    }
};