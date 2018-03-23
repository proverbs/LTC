/*bfs*/

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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;
        int lt = 0;
        vector<pair<TreeNode*, int> > q, tq;
        tq.push_back(make_pair(root, 0));
        int lst = 0;
        vector<int> emp;
        while (lt < q.size() || !tq.empty()) {
            if (lt == q.size()) {
                res.push_back(emp);
                for (int i = tq.size() - 1; i >= 0; i --) {
                    q.push_back(tq[i]);
                    res[lst].push_back(tq[i].first->val);
                }
                tq.clear();
                lst ++;
            } else {
                pair<TreeNode*, int> x = q[lt ++];
                if (lst & 1) {
                    if (x.first->left != NULL) tq.push_back(make_pair(x.first->left, x.second + 1));
                    if (x.first->right != NULL) tq.push_back(make_pair(x.first->right, x.second + 1));
                } else {
                    if (x.first->right != NULL) tq.push_back(make_pair(x.first->right, x.second + 1));
                    if (x.first->left != NULL) tq.push_back(make_pair(x.first->left, x.second + 1));
                }
                
            }
        }
        return res;
    }
};