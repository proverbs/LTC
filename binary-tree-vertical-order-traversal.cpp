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
    map<int, vector<int>> res;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        res.clear();
        bfs(root);
        vector<vector<int>> r;
        map<int, vector<int>>::iterator it;
        for (it = res.begin(); it != res.end(); it ++) {
            r.push_back(it->second);
        }
        return r;
    }
    
    void bfs(TreeNode *x) {
        int d;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(x, 0));
        
        while (!q.empty()) {
            x = q.front().first;
            d = q.front().second;
            q.pop();
            if (!x) continue;
            if (!res.count(d)) res[d] = vector<int>();
            res[d].push_back(x->val);
            q.push(make_pair(x->left, d - 1));
            q.push(make_pair(x->right, d + 1));
        }
    }
    
};