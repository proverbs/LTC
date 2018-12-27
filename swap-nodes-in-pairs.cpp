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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = NULL;
        ListNode *st = head, *ed, *tmp, *res;
        while (st) {
            ed = st->next;
            if (ed) {
                tmp = ed->next;
                ed->next = st;
                st->next = tmp;
                if (p) p->next = ed;
                else res = ed;
                p = st;
                st = tmp;
            } else {
                p->next = st;
                break;
            }
        }
        return res;
    }
};