// get the elements not less than x

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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode *lg_head = NULL, *lg = NULL;
        ListNode *p = head, *q = p->next;
        while (q) {
            if (q->val >= x) {
                if (lg) lg->next = q, lg = q;
                else lg_head = lg = q;
                p->next = q->next;
                q->next = NULL;
                q = p->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        
        if (head->val >= x) {
            ListNode* new_head = head->next;
            head->next = lg_head, lg_head = head;
            head = new_head;
        }
        
        if (head) {
            p = head;
            while (p->next) p = p->next;
            p->next = lg_head;
        } else {
            head = lg_head;
        }
        
        return head;
    }
};