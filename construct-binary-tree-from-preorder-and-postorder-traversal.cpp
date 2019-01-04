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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return dfs(pre, 0, pre.size() - 1, post, 0, post.size() - 1);
    }
    
    TreeNode* dfs(vector<int>& pre, int pre_lt, int pre_rt, vector<int>& post, int post_lt, int post_rt) {
        if (pre_rt < pre_lt) return NULL;
        TreeNode* x = new TreeNode(pre[pre_lt]);
        if (pre_lt == pre_rt) return x;
        
        unordered_map<int, bool> cnt;
        int n = 0;
        for (int i = 0; i < pre_rt - pre_lt; i ++) {
            int nlt = pre_lt + i + 1;
            int mlt = post_lt + i;
            
            if (cnt.count(pre[nlt])) n --;
            else cnt[pre[nlt]] = 1, n ++;
            if (cnt.count(post[mlt])) n --;
            else cnt[post[mlt]] = 1, n ++;
            
            if (!n) {
                x->left = dfs(pre, pre_lt + 1, nlt, post, post_lt, mlt);
                x->right = dfs(pre, nlt + 1, pre_rt, post, mlt + 1, post_rt - 1);
                return x;
            }
        }
    }
};