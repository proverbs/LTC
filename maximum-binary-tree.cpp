// a better way is to use segment tree to maintain queries for maximum of the range

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return construct(nums, 0, nums.size() - 1);
    }
    
    TreeNode* construct(vector<int>& nums, int lt, int rt) {
        if (lt > rt) return NULL;
        if (lt == rt) return new TreeNode(nums[lt]);
        int idx = lt;
        for (int i = lt + 1; i <= rt; i ++)
            if (nums[i] > nums[idx]) idx = i;
        TreeNode* cur = new TreeNode(nums[idx]);
        cur->left = construct(nums, lt, idx - 1);
        cur->right = construct(nums, idx + 1, rt);
        return cur;
    }
};