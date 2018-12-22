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
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode *p = head;
        while (p) p = p->next, len ++;
        if (len <= 1) return;
        
        // split the linked list
        len = (len + 1) / 2;
        p = head;
        while (len -- != 1) p = p->next;
        ListNode *z = p->next;
        p->next = NULL;
        
        // reverse the later linked list
        ListNode *q = z->next, *t;
        p = z;
        while (q) {
            t = q->next;
            q->next = p;
            p = q;
            q = t;
        }
        z->next = NULL;
        z = p;
        
        // merge
        ListNode *u, *y = head;
        while (y && z) {
            t = y->next;
            u = z->next;
            y->next = z;
            z->next = t;
            y = t;
            z = u;
        }
    }
};