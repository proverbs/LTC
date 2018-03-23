/*dfs建树*/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int lt = 0, rt = nums.size() - 1;
        TreeNode* x = NULL;
        build(nums, lt, rt, &x);
        return x;
    }
    
    void build(vector<int>& nums, int lt, int rt, TreeNode** x) {// 指向指针的指针
        if (lt > rt) return;
        int mid = lt + rt >> 1;
        *x = new TreeNode(nums[mid]);
        build(nums, lt, mid - 1, &((*x)->left));
        build(nums, mid + 1, rt, &((*x)->right));
    }
};