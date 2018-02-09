/*pointer*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *q = head;
        while (q) {
            q = q->next;
            len ++;
        }
        n = len - n;
        if (n == 0) return head->next;
        n --;
        ListNode *p = head;
        while (n --) {
            p = p->next;
        }
        q = p->next;
        p->next = q ? q->next : q;
        return head;
    }
};