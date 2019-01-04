// follow-up: maintain the size of each subtree, then each query will be O(logn).

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
    unordered_map<TreeNode*, int> sz;
    int kthSmallest(TreeNode* root, int k) {
        sz.clear();
        sz[NULL] = 0;
        dfs(root);
        return getelement(root, k);
    }
    
    void dfs(TreeNode* x) {
        if (!x) return;
        sz[x] = 1;
        dfs(x->left);
        dfs(x->right);
        sz[x] += sz[x->left] + sz[x->right];
    }
    
    int getelement(TreeNode* x, int k) {
        if (sz[x->left] + 1 == k) return x->val;
        else if (sz[x->left] + 1 < k) return getelement(x->right, k - 1 - sz[x->left]);
        else return getelement(x->left, k);
    }
};