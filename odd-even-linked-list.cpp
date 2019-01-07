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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode *p = head, *q, *t, *ehead = NULL, *cur;
        while (p) {
            if (p->next) q = p->next;
            else break;
            t = q->next;
            p->next = t;
            q->next = NULL;
            if (ehead) cur->next = q, cur = q;
            else ehead = cur = q;
            p = p->next;
        }
        p = head;
        while (p->next) p = p->next; 
        p->next = ehead;
        return head;
    }
};