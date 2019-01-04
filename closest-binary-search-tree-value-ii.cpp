// O(n) for initilizing size, O(logn*log(MAX_DIFF)) for binary searching and checking
// if k is much smaller than n, then we can find k predecessors and k successors using stack.

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
    int min_val, max_val;
    vector<int> d;
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        sz.clear();
        sz[NULL] = 0;
        min_val = root->val;
        max_val = root->val;
        dfs(root);
        double lt = 0.1, rt = 1.0 + max(fabs(max_val - target), fabs(min_val - target));
        double res;
        while (rt - lt > 0.1) {
            double mid = (lt + rt) / 2;
            if (getsize(root, target + mid) - getsize(root, target - mid) >= k) 
                res = mid, rt = mid;
            else lt = mid;
        }

        d.clear();
        getelements(root, target - res, target + res);
        return d;
    }
    
    void dfs(TreeNode* x) {
        if (!x) return;
        max_val = max(max_val, x->val);
        min_val = min(min_val, x->val);
        sz[x] = 1;
        dfs(x->left);
        dfs(x->right);
        sz[x] += sz[x->left] + sz[x->right];
    }
    
    int getsize(TreeNode* x, double val) {
        if (!x) return 0;
        if (x->val < val) {
            return sz[x->left] + 1 + getsize(x->right, val);
        } else {
            return getsize(x->left, val);
        }
    }
    
    void getelements(TreeNode *x, double lt, double rt) {
        if (!x) return;
        if (x->val < lt) {
            getelements(x->right, lt, rt);
        } else if (x->val > rt){
            getelements(x->left, lt, rt);
        } else {
            getelements(x->left, lt, 0.1 + x->val);
            d.push_back(x->val);
            getelements(x->right, -0.1 + x->val, rt);
        }
    }
};