// same as build BST from sorted array
// O(n) solution using inorder traversal: ttps://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solution/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head, *q = head;
        while (p) p = p->next, len ++;
        if (!len) return NULL;
        if (len == 1) {
            TreeNode* x = new TreeNode(head->val);
            return x;
        }
        
        p = head;
        for (int i = 0; i < len / 2; i ++) q = p, p = p->next;
        q->next = NULL;
        TreeNode* x = new TreeNode(p->val);
        x->left = sortedListToBST(head);
        x->right = sortedListToBST(p->next);
        return x;
    }
};