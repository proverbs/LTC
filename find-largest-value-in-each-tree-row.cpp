/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// BFS

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *x = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (res.size() <= depth) res.push_back(x->val);
            else res[depth] = max(res[depth], x->val);
            if (x->left) q.push(make_pair(x->left, depth + 1));
            if (x->right) q.push(make_pair(x->right, depth + 1));
        }
        return res;
    }
};


// DFS
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* x, int depth, vector<int>& res) {
        if (!x) return;
        if (res.size() <= depth) res.push_back(x->val);
        else res[depth] = max(res[depth], x->val);
        dfs(x->left, depth + 1, res);
        dfs(x->right, depth + 1, res);
    }
};