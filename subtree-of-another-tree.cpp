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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) return false;
        if (isEqual(s, t)) return true;
        return isSubtree(s->left, t) | isSubtree(s->right, t);
    }

    bool isEqual(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        else if (s == NULL || t == NULL) return false;
        else {
            if (s->val == t->val) {
                return isEqual(s->left, t->left) & isEqual(s->right, t->right);
            } else {
                return false;
            }
        }
    }
};