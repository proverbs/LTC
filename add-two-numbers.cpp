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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head, *now;
        head = now = new ListNode(0);
        int jin = 0;
        bool fg = false;
        while (l1 || l2 || jin) {
            int sm = jin;
            if (l1) {
                sm += l1->val;
                l1 = l1->next;   
            }
            if (l2) {
                sm += l2->val;
                l2 = l2->next;
            }
            jin = (sm / 10);
            sm %= 10;
            ListNode *p = new ListNode(sm);
            now->next = p;
            now = p;
        }
        return head->next;
    }
};
