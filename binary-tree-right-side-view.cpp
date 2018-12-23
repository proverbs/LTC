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
    unordered_map<TreeNode*, int> depth;
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        get_depth(root);
        res.clear();
        
        view(root, 0);
        return res;
    }
    
    int get_depth(TreeNode *x) {
        if (!x) return 0;
        depth[x] = 1 + max(get_depth(x->left), get_depth(x->right));
        return depth[x];
    }
    
    void view(TreeNode *x, int d) { // d: not print for the first d layers of tree x
        if (x == NULL) return;
        if (d) {
            if (x->right == NULL) {
                view(x->left, d - 1);
            } else {
                if (depth[x->right] >= d) view(x->right, d - 1);
                if (x->left && depth[x->left] > depth[x->right]) {
                    view(x->left, max(depth[x->right], d - 1));
                }
            }
            return;
        }
        
        res.push_back(x->val);
        if (x->right == NULL) view(x->left, 0);
        else {
            view(x->right, 0);
            if (x->left && depth[x->left] > depth[x->right]) {
                view(x->left, depth[x->right]);
            }
        }
    }
};