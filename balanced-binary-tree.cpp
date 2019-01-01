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
    typedef pair<int, bool> pr; // <depth, is_balaced>
    bool isBalanced(TreeNode* root) {
        return dfs(root).second;
    }
    
    pr dfs(TreeNode *x) {
        if (!x) return {0, true};
        pr lt = dfs(x->left);
        pr rt = dfs(x->right);
        if (lt.second && rt.second && abs(lt.first - rt.first) <= 1)
            return {max(lt.first, rt.first) + 1, true};
        return {max(lt.first, rt.first) + 1, false};
    }
};