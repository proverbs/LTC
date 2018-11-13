// dfs

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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> vtn;
        if (root == NULL) {
            vtn.push_back(NULL);
            vtn.push_back(NULL);
            return vtn;
        }
        if (root->val == V) {
            vtn.push_back(root);
            vtn.push_back(root->right);
            root->right = NULL;
        } else if (root->val > V) {
            vector<TreeNode*> tmp = splitBST(root->left, V);
            vtn.push_back(tmp[0]);
            root->left = tmp[1];
            vtn.push_back(root);
        } else {
            vector<TreeNode*> tmp = splitBST(root->right, V);
            root->right = tmp[0];
            vtn.push_back(root);
            vtn.push_back(tmp[1]);
        }
        return vtn;
    }
};