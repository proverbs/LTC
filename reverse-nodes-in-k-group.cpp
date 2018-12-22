// tipical: pay attention to details

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1  || head == NULL) return head;  // special judge
        // compute the length
        int len = 0;
        ListNode *t = head;
        while (t) {
            len ++;
            t = t->next;
        }
        // reverse
        int ti = len / k;
        if (ti == 0) return head; // special judge
        k --;
        ListNode *last = NULL, *res, *q, *p, *w;
        while (ti --) {
            p = head;
            q = head->next;
            
            for (int i = 0; i < k; i ++) {
                w = q->next;
                q->next = p;
                p = q;
                q = w;
            }
            if (last) last->next = p;
            else res = p;
            last = head;
            head = q;
        }
        // cout << last->val << q->val << endl;
        last->next = q;
        // while (res) {
        //     cout << res->val << endl;
        //     res = res->next;
        // }
        return res;
    }
};