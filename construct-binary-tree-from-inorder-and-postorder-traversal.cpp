// recursion

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!postorder.size()) return NULL;
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& inorder, int ia, int ib, vector<int>& postorder, int pa, int pb) {
        TreeNode* x = new TreeNode(postorder[pb]);
        int xlt = ia;
        while (inorder[xlt] != postorder[pb]) xlt ++;
        if (ia <= xlt - 1) x->left = build(inorder, ia, xlt - 1, postorder, pa, pa + xlt - ia - 1);
        if (xlt + 1 <= ib) x->right = build(inorder, xlt + 1, ib, postorder, pa + xlt - ia, pb - 1);
        return x;
    }
};