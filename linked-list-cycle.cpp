/*two pointers*/
/*tipical*/

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
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        ListNode *a, *b;
        a = b = head;
        while (a != NULL && b != NULL) {
            a = a->next;
            b = b->next;
            if (b == NULL) return false;
            b = b->next;
            if (a == b) return true;
        }
        if (a == NULL || b == NULL) return false;
        return true;
    }
};