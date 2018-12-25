// O (n)

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == m) return head;
        
        ListNode *p = head, *q = NULL;
        for (int i = 0; i < m - 1; i ++) {
            q = p;
            p = p->next;
        }
        
        ListNode *y = p, *z = p->next;
        for (int i = 0; i < n - m; i ++) {
            ListNode *t = z->next;
            z->next = y;
            y = z;
            z = t;
        }
        
        if (q) {
            q->next = y;
            p->next = z;
            return head;
        } else {
            p->next = z;
            return y;
        }
    }
};