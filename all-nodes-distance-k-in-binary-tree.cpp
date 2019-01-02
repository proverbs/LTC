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
    int dist;
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        dist = K;
        res.clear();
        if (dist) dfs(root, target, 0);
        else res.push_back(target->val);
        return res;
    }
    
    int dfs(TreeNode* x, TreeNode* t, int d) { // dfs for target's depth
        if (!x) return -1;
        
        int rt = -1;
        if (x == t) {
            rt = d;
            go_down(x->left, dist - 1);
            go_down(x->right, dist - 1);
        } else {
            int ltv = dfs(x->left, t, d + 1);
            int rtv = dfs(x->right, t, d + 1);
            
            if (ltv >= 0) {
                rt = ltv;
                if (ltv - d == dist) res.push_back(x->val);
                else if (ltv - d < dist) go_down(x->right, dist - (ltv - d) - 1);
            } else if (rtv >= 0) {
                rt = rtv;
                if (rtv - d == dist) res.push_back(x->val);
                else if (rtv - d < dist) go_down(x->left, dist - (rtv - d) - 1);
            }
        }
        
        return rt;
    }
    
    void go_down(TreeNode* x, int d) {
        if (!x) return;
        if (d == 0) res.push_back(x->val);
        else {
            go_down(x->left, d - 1);
            go_down(x->right, d - 1);
        }
    }
};