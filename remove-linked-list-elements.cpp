/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return head;
        ListNode *z = removeElements(head->next, val);
        head->next = z;
        if (head->val == val) return z;
        else return head;
    }
};