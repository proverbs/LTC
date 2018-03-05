/*dp*/

#include <map>
#include <iostream>
#include <vector>

using namespace std;

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
    int maxPathSum(TreeNode* root) {
        map<TreeNode*, int> dp;
        map<TreeNode*, TreeNode*> son;
        // map<TreeNode*> f; // 多叉树使用，表示第二长路径
        dp[NULL] = 0;
        int res = -9999999;
        traverse(root, dp, son);
        calc(root, dp, son, res);
        return res;
    }

    void traverse(TreeNode* x, map<TreeNode*, int>& dp, map<TreeNode*, TreeNode*>& son) {
        if (x == NULL) return;
        dp[x] = x->val;
        traverse(x->left, dp, son);
        traverse(x->right, dp, son);
        if (dp[x->left] > dp[x->right]) dp[x] += dp[x->left], son[x] = x->left;
        else dp[x] += dp[x->right], son[x] = x->right;
        if (dp[x] < x->val) dp[x] = x->val;// 细节
    }

    void calc(TreeNode* x, map<TreeNode*, int>& dp, map<TreeNode*, TreeNode*>& son, int &res) {
        if (x == NULL) return;
        if (son[x] == x->left) res = max(res, dp[x] + dp[x->right]);
        else res = max(res, dp[x] + dp[x->left]);
        res = max(res, dp[x]); // 细节
        //cout << x << "  " << dp[x] << endl;
        calc(x->left, dp, son, res);
        calc(x->right, dp, son, res);
    }
};