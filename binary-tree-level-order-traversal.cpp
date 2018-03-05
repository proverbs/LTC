/*dfs, bfs*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        vector<pair<TreeNode*, int> > q;
        int lt = 0;
        q.push_back(make_pair(root, 1));
        while (lt < q.size()) {
            pair<TreeNode*, int> x = q[lt ++];
            if (res.size() < x.second) {
                vector<int> v;
                res.push_back(v);
            }
            res[x.second - 1].push_back(x.first->val);
            if (x.first->left != NULL) q.push_back(make_pair(x.first->left, x.second + 1));
            if (x.first->right != NULL) q.push_back(make_pair(x.first->right, x.second + 1));
        }
        return res;
    }
};