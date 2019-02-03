// dfs to compute the distance to leave

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<int, vector<int>> res;
        dfs(root, res);
        vector<vector<int>> rt;
        for (int i = 1; ; i++) {
            if (!res.count(i)) break;
            rt.push_back(res[i]);
        }
        return rt;
    }
    
    int dfs(TreeNode* root, unordered_map<int, vector<int>>& res) {
        if (!root) return 0;
        int d = max(dfs(root->right, res), dfs(root->left, res)) + 1;
        if (res.count(d)) res[d].push_back(root->val);
        else res[d] = vector<int>({root->val});
        return d;
    }
};