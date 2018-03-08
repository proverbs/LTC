/*pointer operation*/

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* t =  head->next;
        head->next = NULL;
        return rev(head, t);
    }

    ListNode* rev(ListNode* x, ListNode* y) {
        if (y == NULL) return x;
        ListNode* t = y->next;
        y->next = x;
        return rev(y, t);
    }
};