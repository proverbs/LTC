// tree serialization

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
    unordered_map<string, int> mp;
    vector<TreeNode*> xt;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mp.clear();
        dfs(root);
        return xt;
    }
    
    string dfs(TreeNode* x) {
        string res;
        if (!x) {
            res = "#,";
            return res;
        } else {
            res = to_string(x->val) + ",";
            res += dfs(x->left);
            res += dfs(x->right);
            res += "#,";
            if (mp.count(res)) {
                if (mp[res] ++ == 1) xt.push_back(x);
            }
            else mp[res] = 1;
            
            return res;
        }
    }
};