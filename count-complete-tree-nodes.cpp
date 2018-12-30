// O(logn*logn)
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
    int countNodes(TreeNode* root) {
        TreeNode *x = root;
        int res = 0;
        while (x) {
            res ++;
            int dlt = get_left_depth(x->left);
            int drt = get_left_depth(x->right);
            if (dlt == drt) {
                res += (1 << dlt) - 1;
                x = x->right;
            } else {
                res += (1 << drt) - 1;
                x = x->left;
            }
        }
        return res;
    }
    
    int get_left_depth(TreeNode *x) {
        int d = 0;
        while (x) d ++, x = x->left;
        return d;
    }
};